#include "demo-data.h"
uint32_t pixels[HEIGHT * WIDTH];
int main() {
	setup();
	dump_pixel_to_ppm(pixels, WIDTH, HEIGHT, "see.ppm");
}
