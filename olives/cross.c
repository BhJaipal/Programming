#include "cross.h"
#include "olive.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

App* create_app(size_t width, size_t height, void (*draw)(uint32_t *pixels)) {
	App* app = malloc(sizeof(App));
#if defined X11
	X11Data* data = malloc(sizeof(X11Data));
	*data = create_x11_window(0, 0, width, height);
	data->draw = draw;
#elif defined WAYLAND
	client_state *data = malloc(sizeof(client_state));
	*data = create_state(draw, width, height, 0, 0);
#elif defined WINDOWS
	WinData data = {NULL, width, height};
	app->draw = draw;
#endif /* X11 */

	app->data = data;
	return app;
}
void run_app(App *app, char *title) {
#if defined X11
	XSelectInput(app->data->display, app->data->window, ExposureMask | KeyPressMask);
	XMapWindow(app->data->display, app->data->window);
	x11_render(app->data, NULL);

	XCloseDisplay(app->data->display);
#elif defined WAYLAND
	get_registry(app->data, title);
    while (wl_display_dispatch(app->data->wl_display)) {
    }
#elif defined WINDOWS
	app->draw(app->data.pixels);
	set_global(app->data);
	create_window(title);
#endif /* X11 */
}
