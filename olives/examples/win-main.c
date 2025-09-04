#include "demo-data.h"
#include <stdint.h>
uint32_t pixels[WIDTH * HEIGHT];

int Main() {
    setup();
    set_global((WinData) { .height = HEIGHT, .width = WIDTH, .pixels = pixels });
    create_window("Hello World");
}
