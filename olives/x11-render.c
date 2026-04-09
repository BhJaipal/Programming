#include <X11/X.h>
#include <stdint.h>
#include <malloc.h>
#include "olive.h"
#include <X11/Xlib.h>
#include <stdio.h>
#include <unistd.h>

void x11_render(X11Data *data, void (*draw)(uint32_t *pixels)) {
	uint32_t *pixels = malloc(data->width * data->height * 4);
	if (draw) draw(pixels);
	else data->draw(pixels);
	XEvent e;
	XGCValues vals[] = {
		(XGCValues){GXcopy, 1, 0, 1, 2, LineSolid, CapButt, JoinMiter, FillSolid, EvenOddRule, ArcPieSlice, 0, 0, 0, 0, 1, ClipByChildren, 1, 0, 0, None, 0, 4}
	};
	GC gc = XCreateGC(data->display, data->window, 16, vals);
	while (1) {
		XNextEvent(data->display, &e);
		for (size_t i = 0; i < data->width * data->height; i++) {
			if (pixels[i] != 0xFFFFFFFF) {
				XSetForeground(data->display, gc, pixels[i]);
				XDrawPoint(data->display, data->window, gc, i % data->width, i / data->width);
			}
		}
		if (e.type != Expose) break;
   }
}
X11Data create_x11_window(size_t x, size_t y, size_t width, size_t height) {
	Display *display = XOpenDisplay(NULL);
	int screen = DefaultScreen(display);
	Window win = XCreateSimpleWindow(display, RootWindow(display, screen), x, y, width, height, 1,
								  BlackPixel(display, screen), WhitePixel(display, screen));
	return (struct X11Data){.display = display, .window = win, width, height, x, y};
}
