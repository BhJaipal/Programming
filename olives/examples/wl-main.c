#define WAYLAND
#include "demo-data.h"
#include <sys/mman.h>
#include <unistd.h>

void *draw(int fd) {
    uint32_t *pixels = mmap(NULL, WIDTH * HEIGHT * 4,
            PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	setup();

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
