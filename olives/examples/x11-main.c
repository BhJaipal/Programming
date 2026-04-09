#include <stddef.h>
#include <stdint.h>
#include "demo-data.h"

void draw(uint32_t *pixels) {
	setup();
}

int main() {
	X11Data data = create_x11_window(800, 500, WIDTH, HEIGHT);
	XSelectInput(data.display, data.window, ExposureMask | KeyPressMask);
	XMapWindow(data.display, data.window);

	x11_render(&data, draw);

	XCloseDisplay(data.display);
}
