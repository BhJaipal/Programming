#include "demo-data.h"
#include <sys/mman.h>
#include <unistd.h>

void draw(uint32_t *pixels) {
	setup();
}

int main() {
	client_state state = create_state(draw, WIDTH, HEIGHT, 100, 600);
	get_registry(&state, "New");
    while (wl_display_dispatch(state.wl_display)) {
    }

    return 0;
}
