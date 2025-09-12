#include <stddef.h>
#include <stdint.h>
#include "demo-data.h"

void draw(uint32_t *pixels) {
	setup();
}

int main() {
	X11Data data = create_x11_window();
	XSelectInput(data.display, data.window, ExposureMask | KeyPressMask);
	XMapWindow(data.display, data.window);

	data.draw = draw;
	x11_render(WIDTH, HEIGHT, &data);

	XCloseDisplay(data.display);
}
