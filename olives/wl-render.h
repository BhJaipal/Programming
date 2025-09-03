#define WAYLAND
#include "xdg-shell-client-protocol.h"
#include <stddef.h>

/* Wayland code */
typedef struct client_state {
	/* Globals */
	struct wl_display *wl_display;
	struct wl_registry *wl_registry;
	struct wl_shm *wl_shm;
	struct wl_compositor *wl_compositor;
	struct xdg_wm_base *xdg_wm_base;
	/* Objects */
	struct wl_surface *wl_surface;
	struct xdg_surface *xdg_surface;
	struct xdg_toplevel *xdg_toplevel;
	struct wl_keyboard *keyboard;
	struct wl_seat *seat;
	char super_on;
	char q_on;

	/* User defined area */
	void *(*draw)(int fd);
	void *(*keypress)(
		struct client_state *self,
		struct wl_keyboard *wl_keyboard,
		uint32_t serial,
		uint32_t time,
		uint32_t key,
		uint32_t state
	);
	size_t width;
	size_t height;
} client_state;

client_state create_state();
void get_registry(client_state *state, char *title);
