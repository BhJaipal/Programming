#define USE_GTK
#include "../olive.h"
#define HEIGHT 200
#define WIDTH 300

#define setup() 													\
	fill_color_all(pixels, WIDTH, HEIGHT, 0xFFFFFFFF);				\
	fill_circle(pixels, WIDTH, HEIGHT, 150, 120, 20, 0xFF3F3F7F);	\
	fill_oval(pixels, WIDTH, HEIGHT, 50, 70, 20, 40, 0xFF00FF90);	\
	empty_oval(pixels, WIDTH, HEIGHT, 230, 50, 40, 20, 0xFF00FF90); \
	fill_rect(pixels, WIDTH, HEIGHT, 50, 70, 60, 60, 0x20FF9000);	\
	empty_rect(pixels, WIDTH, HEIGHT, 200, 100, 60, 60, 0xFFFF9000);\
	empty_circle(pixels, WIDTH, HEIGHT, 150, 50, 20, 0xFF3F3F7F);
uint32_t pixels[HEIGHT * WIDTH];

int main(int c, char **v) {
	setup();
	GtkData data("Cairo renderer", WIDTH, HEIGHT, pixels);
	return data.run();
}
