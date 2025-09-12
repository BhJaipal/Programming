#include "demo-data.h"
#include "../cross.h"

void draw(uint32_t *pixels) {
	setup();
}

int main() {
	App* app = create_app(WIDTH, HEIGHT, draw);
	run_app(app, "Hello");
}
