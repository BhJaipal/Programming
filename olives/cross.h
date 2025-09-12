#pragma once
#include <stdint.h>
#include "olive.h"

typedef struct App App;
struct App {
#if defined X11
	size_t width, height;
	X11Data* data;
#elif defined WAYLAND
	client_state* data;
#elif defined WINDOWS
	WinData data;
	void (*draw)(uint32_t *pixels);
#endif
};

App* create_app(size_t width, size_t height, void (*draw)(uint32_t *pixels));
void run_app(App *app, char *title);
