#define USE_GL
#include "demo-data.h"

uint32_t pixels[HEIGHT * WIDTH];
int main() {
	setup();
	return gl_render(pixels, WIDTH, HEIGHT, "GLFW Renderer");
}
