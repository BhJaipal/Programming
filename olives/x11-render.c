#include <stdint.h>
#include <malloc.h>
#include "olive.h"
#include <X11/Xlib.h>
#include <unistd.h>

void x11_render(size_t width, size_t height, X11Data *data) {
	uint32_t *pixels = malloc(width * height * 4);
	data->draw(pixels);
	XEvent e;
	XGCValues vals[] = {
		(XGCValues){GXcopy, 1, 0, 1, 2, LineSolid, CapButt, JoinMiter, FillSolid, EvenOddRule, ArcPieSlice, 0, 0, 0, 0, 1, ClipByChildren, 1, 0, 0, None, 0, 4}
	};
	GC gc = XCreateGC(data->display, data->window, 16, vals);
	while (1) {
		XNextEvent(data->display, &e);
		if (e.type == Expose) {
			for (size_t i = 0; i < width * height; i++) {
				if (pixels[i] != 0xFFFFFFFF) {
					XSetForeground(data->display, gc, pixels[i]);
					XDrawPoint(data->display, data->window, gc, i % width, i / width);
				}
			}
		}
		if (e.type == KeyPress)
			break;
   }
}
X11Data create_x11_window() {
	Display *display = XOpenDisplay(NULL);
	int screen = DefaultScreen(display);
	Window win = XCreateSimpleWindow(display, RootWindow(display, screen), 10, 10, 400, 400, 1,
								  BlackPixel(display, screen), WhitePixel(display, screen));
	return (struct X11Data){.display = display, .window = win};
}
