#define USE_GTK
#include "demo-data.h"
uint32_t pixels[WIDTH * HEIGHT];

int main(int c, char **v) {
	setup();
	GtkData data("Gtkmm 3 App", WIDTH, HEIGHT, pixels);
	return data.run();
}
