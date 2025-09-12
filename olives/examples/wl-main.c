#include "demo-data.h"
#include <sys/mman.h>
#include <unistd.h>

void draw(uint32_t *pixels) {
	setup();
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
