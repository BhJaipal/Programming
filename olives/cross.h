#pragma once
#include <stdint.h>
#include "olive.h"

typedef struct App App;
struct App {
#if DISPLAY == X11
	size_t width, height;
	X11Data* data;
#elif DISPLAY == WAYLAND
	client_state* data;
#elif DISPLAY == WINDOWS
	WinData data;
	void (*draw)(uint32_t *pixels);
#endif
};

App* create_app(size_t width, size_t height, void (*draw)(uint32_t *pixels));
void run_app(App *app, char *title);
