/*
 * This is inspired from https://github.com/tsoding/olive.c, A recreational programmer
 * Who makes awesome C, rust content
 * Recommended to watch
 * https://youtube.com/@tsoding
 */
#include <X11/X.h>
#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <X11/Xlib.h>

void merge_color(uint32_t *pixel_loc, size_t color);
void fill_oval(uint32_t *pixels, size_t width, size_t height, size_t cx, size_t cy, size_t a, size_t b, uint32_t color);
void empty_oval(uint32_t *pixels, size_t width, size_t height, size_t cx, size_t cy, size_t a, size_t b, uint32_t color);
void fill_circle(uint32_t *pixels, size_t width, size_t height, size_t cx, size_t cy, size_t r, uint32_t color);
void empty_circle(uint32_t *pixels, size_t width, size_t height, size_t cx, size_t cy, size_t r, uint32_t color);
void fill_rect(uint32_t *pixels, size_t width, size_t height, size_t x, size_t y, size_t w, size_t h, uint32_t color);
void empty_rect(uint32_t *pixels, size_t width, size_t height, size_t x, size_t y, size_t w, size_t h, uint32_t color);
void fill_color_all(uint32_t *pixels, size_t width, size_t height, uint32_t color);

#if defined(MSDOS) || defined(OS2) || defined(WIN32) || defined(__CYGWIN__)
__attribute__((warning("Not sure if your OS supports PPM image files, if it doesn't, I missed the part where that's my problem")))
#endif
int dump_pixel_to_ppm(uint32_t *pixels, size_t width, size_t height, char *file_path);

typedef struct X11Data {
	Display *display;
	Window window;
} X11Data;
X11Data create_x11_window();
void render_to_x11(uint32_t *pixels, size_t width, size_t height, X11Data *display, XEvent *e);
