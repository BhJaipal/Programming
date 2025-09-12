#include "cross.h"
#include "olive.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

App* create_app(size_t width, size_t height, void (*draw)(uint32_t *pixels)) {
	App* app = malloc(sizeof(App));
#if DISPLAY == X11
	app->width = width;
	app->height = height;
	X11Data* data = malloc(sizeof(X11Data));
	*data = create_x11_window();
	data->draw = draw;
#elif DISPLAY == WAYLAND
	client_state *data = malloc(sizeof(client_state));
	*data = create_state();
	data->width = width;
	data->height = height;
	data->draw = draw;
#elif DISPLAY == WINDOWS
	WinData data = {NULL, width, height};
	app->draw = draw;
#endif /* X11 */

	app->data = data;
	return app;
}
void run_app(App *app, char *title) {
#if DISPLAY == X11
	XSelectInput(app->data->display, app->data->window, ExposureMask | KeyPressMask);
	XMapWindow(app->data->display, app->data->window);
	x11_render(app->width, app->height, app->data);

	XCloseDisplay(app->data->display);
#elif DISPLAY == WAYLAND
	get_registry(app->data, title);
    while (wl_display_dispatch(app->data->wl_display)) {
    }
#elif DISPLAY == WINDOWS
	app->draw(app->data.pixels);
	set_global(app->data);
	create_window(title);
#endif /* X11 */
}
