#include <stddef.h>
#define X11
#include "demo-data.h"
uint32_t pixels[HEIGHT * WIDTH];

int main() {
	X11Data data = create_x11_window();
	XSelectInput(data.display, data.window, ExposureMask | KeyPressMask);
	XMapWindow(data.display, data.window);
	setup();

	render_to_x11(pixels, WIDTH, HEIGHT, &data);

	XCloseDisplay(data.display);
}
