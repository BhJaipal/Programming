#include <stddef.h>
#include "olive.h"

#define HEIGHT 200
#define WIDTH 300
uint32_t pixels[HEIGHT * WIDTH];

int main() {
	X11Data data = create_x11_window();
	XSelectInput(data.display, data.window, ExposureMask | KeyPressMask);
	XMapWindow(data.display, data.window);

	fill_color_all(pixels, WIDTH, HEIGHT, 0xFFFFFFFF);
	fill_circle(pixels, WIDTH, HEIGHT, 150, 120, 20, 0xFF3F3F7F);
	fill_oval(pixels, WIDTH, HEIGHT, 50, 70, 20, 40, 0xFF00FF90);
	empty_oval(pixels, WIDTH, HEIGHT, 230, 50, 40, 20, 0xFF00FF90);
	fill_rect(pixels, WIDTH, HEIGHT, 50, 70, 60, 60, 0x20FF9000);
	empty_rect(pixels, WIDTH, HEIGHT, 200, 100, 60, 60, 0xFFFF9000);
	empty_circle(pixels, WIDTH, HEIGHT, 150, 50, 20, 0xFF3F3F7F);

	render_to_x11(pixels, WIDTH, HEIGHT, &data);

	XCloseDisplay(data.display);
}
