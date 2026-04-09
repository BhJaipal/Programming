#include "demo-data.h"
// This is one of rare times when I added windows support
// This is a simple cross platform rendering library
// If it is windows, it will directly utilize CreateWindow api
// If linux, based on currecnt display server, it will
// automatically select between X11 and wayland
#include "../cross.h"

void draw(uint32_t *pixels) {
	// just a macro that automatically draw some shapes
	setup();
}

int main() {
	App* app = create_app(WIDTH, HEIGHT, draw);
	run_app(app, "Hello");
}
