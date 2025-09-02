#include <linux/input-event-codes.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <wayland-client-protocol.h>
#include <errno.h>
#include <fcntl.h>
#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include <sys/mman.h>
#include <time.h>
#include <unistd.h>
#include <linux/input.h>
#include <wayland-client.h>
#include "xdg-shell-client-protocol.h"
#include "wl-client.h"

/* Shared memory support code */
static void
randname(char *buf) {
    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    long r = ts.tv_nsec;
    for (int i = 0; i < 6; ++i) {
        buf[i] = 'A'+(r&15)+(r&16)*2;
        r >>= 5;
    }
}

static int
create_shm_file(void) {
    int retries = 100;
    do {
        char name[] = "/wl_shm-XXXXXX";
        randname(name + sizeof(name) - 7);
        --retries;
        int fd = shm_open(name, O_RDWR | O_CREAT | O_EXCL, 0600);
        if (fd >= 0) {
            shm_unlink(name);
            return fd;
        }
    } while (retries > 0 && errno == EEXIST);
    return -1;
}

static int
allocate_shm_file(size_t size) {
    int fd = create_shm_file();
    if (fd < 0)
        return -1;
    int ret;
    do {
        ret = ftruncate(fd, size);
    } while (ret < 0 && errno == EINTR);
    if (ret < 0) {
        close(fd);
        return -1;
    }
    return fd;
}

static void
wl_buffer_release(void *data, struct wl_buffer *wl_buffer) {
    /* Sent by the compositor when it's no longer using this buffer */
    wl_buffer_destroy(wl_buffer);
}

static const struct wl_buffer_listener wl_buffer_listener = {
    .release = wl_buffer_release,
};

static struct wl_buffer *
draw_frame(int fd, struct client_state *state) {
    struct wl_shm_pool *pool = wl_shm_create_pool(state->wl_shm, fd, state->width * 4 * state->height);
    struct wl_buffer *buffer = wl_shm_pool_create_buffer(pool, 0,
            state->width, state->height, state->width * 4, WL_SHM_FORMAT_XRGB8888);
    wl_shm_pool_destroy(pool);
    close(fd);

    wl_buffer_add_listener(buffer, &wl_buffer_listener, NULL);
    return buffer;
}

static void
xdg_surface_configure(void *data,
        struct xdg_surface *xdg_surface, uint32_t serial) {
    client_state *state = data;
    xdg_surface_ack_configure(xdg_surface, serial);

    int fd = allocate_shm_file(state->width * 4 * state->height);
    if (fd == -1) {
		return;
    }
	void *pixels = state->draw(fd);

    struct wl_buffer *buffer = draw_frame(fd, state);
	munmap(pixels, state->width * 4 * state->height);
    wl_surface_attach(state->wl_surface, buffer, 0, 0);
    wl_surface_commit(state->wl_surface);
}

static const struct xdg_surface_listener xdg_surface_listener = {
    .configure = xdg_surface_configure,
};

static void
xdg_wm_base_ping(void *data, struct xdg_wm_base *xdg_wm_base, uint32_t serial) {
    xdg_wm_base_pong(xdg_wm_base, serial);
}

static const struct xdg_wm_base_listener xdg_wm_base_listener = {
    .ping = xdg_wm_base_ping,
};

static void registry_global(void *data, struct wl_registry *wl_registry,
        uint32_t name, const char *interface, uint32_t version) {
    struct client_state *state = data;
	printf("%s %d\n", interface, name);
    if (strcmp(interface, wl_shm_interface.name) == 0) {
        state->wl_shm = wl_registry_bind(
                wl_registry, name, &wl_shm_interface, 1);
    } else if (strcmp(interface, wl_compositor_interface.name) == 0) {
        state->wl_compositor = wl_registry_bind(
                wl_registry, name, &wl_compositor_interface, 4);
    } else if (strcmp(interface, xdg_wm_base_interface.name) == 0) {
        state->xdg_wm_base = wl_registry_bind(
                wl_registry, name, &xdg_wm_base_interface, 1);
        xdg_wm_base_add_listener(state->xdg_wm_base,
                &xdg_wm_base_listener, state);
    } else if (strcmp(interface, wl_seat_interface.name) == 0) {
		state->seat = wl_registry_bind(wl_registry, name, &wl_seat_interface, 1);
	}
}
static void kbd_key(void *data,
		    struct wl_keyboard *wl_keyboard,
		    uint32_t serial,
		    uint32_t time,
		    uint32_t key,
		    uint32_t state) {
	client_state *client = data;
	if (client->keypress)
		client->keypress(client, wl_keyboard, serial, time, key, state);

	if ((key == KEY_LEFTMETA && key != KEY_LEFTALT)
		|| (key == KEY_RIGHTMETA && key != KEY_RIGHTALT)
	)
		client->super_on = 1;
	else if (key == KEY_Q)
		client->q_on = 1;
	else {
		client->super_on = 0;
		client->q_on = 0;
	}
	if (client->q_on && client->super_on) exit(0);
}
void kbd_keymap(void *data,
		       struct wl_keyboard *wl_keyboard,
		       uint32_t format,
		       int32_t fd,
		       uint32_t size) {}
void kbd_enter(void *data,
		      struct wl_keyboard *wl_keyboard,
		      uint32_t serial,
		      struct wl_surface *surface,
		      struct wl_array *keys) {
}
void kbd_leave(void *data,
		      struct wl_keyboard *wl_keyboard,
		      uint32_t serial,
		      struct wl_surface *surface) {

}
void kbd_modifier(void *data,
			  struct wl_keyboard *wl_keyboard,
			  uint32_t serial,
			  uint32_t mods_depressed,
			  uint32_t mods_latched,
			  uint32_t mods_locked,
			  uint32_t group) {}
struct wl_keyboard_listener keyboard_listener = {kbd_keymap, kbd_enter, kbd_leave, kbd_key, kbd_modifier, NULL};

static void registry_global_remove(void *data,
        struct wl_registry *wl_registry, uint32_t name) {}

static const struct wl_registry_listener wl_registry_listener = {
    .global = registry_global,
    .global_remove = registry_global_remove,
};
client_state create_state() {
    client_state state = { 0 };
    state.wl_display = wl_display_connect(NULL);
    state.wl_registry = wl_display_get_registry(state.wl_display);
	return state;
}

void get_registry(client_state *state, char *title) {
    wl_registry_add_listener(state->wl_registry, &wl_registry_listener, state);
    wl_display_roundtrip(state->wl_display);
	state->keyboard = wl_seat_get_keyboard(state->seat);
	state->q_on = 0;
	state->super_on = 0;
	state->keypress = NULL;

    state->wl_surface = wl_compositor_create_surface(state->wl_compositor);
    state->xdg_surface = xdg_wm_base_get_xdg_surface(
            state->xdg_wm_base, state->wl_surface);
    xdg_surface_add_listener(state->xdg_surface, &xdg_surface_listener, state);
    state->xdg_toplevel = xdg_surface_get_toplevel(state->xdg_surface);
    xdg_toplevel_set_title(state->xdg_toplevel, title);
    wl_surface_commit(state->wl_surface);
	wl_keyboard_add_listener(state->keyboard, &keyboard_listener, state);
}
