#define DISPLAY 2
#include "olive.h"
#include <sys/mman.h>
#include <unistd.h>
#define HEIGHT 200
#define WIDTH 300

void *draw(int fd) {
    uint32_t *pixels = mmap(NULL, WIDTH * HEIGHT * 4,
            PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	fill_color_all(pixels, WIDTH, HEIGHT, 0xFFFFFFFF);
	fill_circle(pixels, WIDTH, HEIGHT, 150, 120, 20, 0xFF3F3F7F);
	fill_oval(pixels, WIDTH, HEIGHT, 50, 70, 20, 40, 0xFF00FF90);
	empty_oval(pixels, WIDTH, HEIGHT, 230, 50, 40, 20, 0xFF00FF90);
	fill_rect(pixels, WIDTH, HEIGHT, 50, 70, 60, 60, 0x20FF9000);
	empty_rect(pixels, WIDTH, HEIGHT, 200, 100, 60, 60, 0xFFFF9000);
	empty_circle(pixels, WIDTH, HEIGHT, 150, 50, 20, 0xFF3F3F7F);

    if (pixels == MAP_FAILED) {
        close(fd);
		return NULL;
    }
	return pixels;
}

int main() {
	client_state state = create_state();
	state.draw = draw;
	state.height = HEIGHT;
	state.width = WIDTH;
	get_registry(&state, "New");
    while (wl_display_dispatch(state.wl_display)) {
    }

    return 0;
}
