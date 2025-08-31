#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wayland-client-core.h>
#include <wayland-client-protocol.h>
#include <wayland-client.h>
#include <wayland-egl-core.h>
#include <wayland-util.h>
#include <unistd.h>
#include "olive.h"
#include <fcntl.h>
#include <sys/mman.h>

#define HEIGHT 200
#define WIDTH 300
uint32_t *pixels;

struct wl_shell *shell = NULL;
struct wl_shm *wl_shm = NULL;
struct wl_compositor *compositor;

static void registry_add_object(void* data, struct wl_registry* registry, uint32_t name, const char* interface, uint32_t version) {
	if (!strcmp(interface,"wl_compositor")) {
		compositor = wl_registry_bind (registry, name, &wl_compositor_interface, 1);
	}
	else if (!strcmp(interface,"wl_shm")) {
		wl_shm = wl_registry_bind (registry, name, &wl_shm_interface, 1);
	}
}
static void registry_remove_object(void* data, struct wl_registry* registry, uint32_t name){}
static struct wl_registry_listener registry_listener = {
    &registry_add_object,
    &registry_remove_object
};

static void shell_surface_ping (void *data, struct wl_shell_surface *shell_surface, uint32_t serial) {
	wl_shell_surface_pong (shell_surface, serial);
}
static void shell_surface_configure (void *data, struct wl_shell_surface *shell_surface, uint32_t edges, int32_t width, int32_t height) {}
static void shell_surface_popup_done (void *data, struct wl_shell_surface *shell_surface) {}
static struct wl_shell_surface_listener shell_surface_listener = {&shell_surface_ping, &shell_surface_configure, &shell_surface_popup_done};

int main() {
	struct wl_display *display = wl_display_connect(NULL);
	struct wl_registry *registry = wl_display_get_registry(display);
	wl_registry_add_listener(registry, &registry_listener, NULL);
	wl_display_dispatch(display);
	wl_display_roundtrip(display);
	struct wl_surface *surface = wl_compositor_create_surface(compositor);
	struct wl_region *region = wl_compositor_create_region(compositor);

	wl_region_add(region, 0, 0, 400, 400);
	struct wl_egl_window *window = wl_egl_window_create(surface, 400, 400);


	char *xdg_runtime_dir = getenv("XDG_RUNTIME_DIR");
	int fd = open(xdg_runtime_dir, O_RDWR|O_EXCL, 0600);
	if (fd == -1) {
		printf("Can't open %s\n", xdg_runtime_dir);
		exit(1);
	}
	size_t size = WIDTH * HEIGHT * 4;

	pixels = mmap(NULL, size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);

	fill_color_all(pixels, WIDTH, HEIGHT, 0xFFFFFFFF);
	fill_circle(pixels, WIDTH, HEIGHT, 150, 120, 20, 0xFF3F3F7F);
	fill_oval(pixels, WIDTH, HEIGHT, 50, 70, 20, 40, 0xFF00FF90);
	empty_oval(pixels, WIDTH, HEIGHT, 230, 50, 40, 20, 0xFF00FF90);
	fill_rect(pixels, WIDTH, HEIGHT, 50, 70, 60, 60, 0x20FF9000);
	empty_rect(pixels, WIDTH, HEIGHT, 200, 100, 60, 60, 0xFFFF9000);
	empty_circle(pixels, WIDTH, HEIGHT, 150, 50, 20, 0xFF3F3F7F);
	struct wl_registry_listener a;

	struct wl_buffer *buffer;
	ftruncate (fd, size);
	struct wl_shm_pool *pool = wl_shm_create_pool(wl_shm, fd, size);
	struct wl_buffer *buff =  wl_shm_pool_create_buffer(pool, 0, WIDTH, HEIGHT, WIDTH * 4, WL_SHM_FORMAT_ABGR8888);
	close(fd);
	wl_surface_attach(surface, buff, 0, 0);
	wl_surface_commit(surface);
	while (1) {
		wl_display_dispatch_pending(display);
	}
	sleep(3);
	wl_buffer_destroy(buff);
	wl_shm_pool_destroy(pool);
	wl_egl_window_destroy(window);
	wl_surface_destroy(surface);
	wl_compositor_destroy(compositor);
	wl_registry_destroy(registry);
	wl_display_disconnect(display);
}
