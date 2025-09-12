#ifndef OLIVES_H
#define OLIVES_H
/*
 * This is inspired from https://github.com/tsoding/olive.c, A recreational programmer
 * Who makes awesome C, rust content
 * Recommended to watch
 * https://youtube.com/@tsoding
 */
#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#define X11 0
#define WAYLAND 2
#define WINDOWS 1
#include "olive-platform.h"

void merge_color(uint32_t *pixel_loc, size_t color);
void fill_oval(uint32_t *pixels, size_t width, size_t height, size_t cx, size_t cy, size_t a, size_t b, uint32_t color);
void empty_oval(uint32_t *pixels, size_t width, size_t height, size_t cx, size_t cy, size_t a, size_t b, uint32_t color);
void fill_circle(uint32_t *pixels, size_t width, size_t height, size_t cx, size_t cy, size_t r, uint32_t color);
void empty_circle(uint32_t *pixels, size_t width, size_t height, size_t cx, size_t cy, size_t r, uint32_t color);
void fill_rect(uint32_t *pixels, size_t width, size_t height, size_t x, size_t y, size_t w, size_t h, uint32_t color);
void empty_rect(uint32_t *pixels, size_t width, size_t height, size_t x, size_t y, size_t w, size_t h, uint32_t color);
void draw_line(uint32_t *pixels, size_t width, size_t height, uint32_t point1[2], uint32_t point2[2], uint32_t color, int line_width);
void fill_color_all(uint32_t *pixels, size_t width, size_t height, uint32_t color);

#if defined(MSDOS) || defined(WIN32) || defined(__WIN32)
__attribute__((warning("Not sure if your OS supports PPM image files, if it doesn't, I missed the part where that's my problem")))
#endif
int dump_pixel_to_ppm(uint32_t *pixels, size_t width, size_t height, char *file_path);

#if defined DISPLAY && DISPLAY == X11
# include <X11/Xlib.h>
typedef struct X11Data {
	Display *display;
	Window window;
	void (*draw)(uint32_t *pixels);
} X11Data;
X11Data create_x11_window();
void x11_render(size_t width, size_t height, X11Data *data);
#endif
#if DISPLAY == WAYLAND
# include "wl-render.h"
#elif DISPLAY == WINDOWS
typedef struct {
	uint32_t *pixels;
	size_t width;
	size_t height;
} WinData;
// Call set_global before this inside void Main(), not main
void create_window(char *title);
void set_global(WinData data);
#endif

#ifdef USE_GTK
# if __cplusplus
#  include <string>
#  include <glibmm/refptr.h>
#  include <gtkmm/application.h>
struct Data {
	uint32_t *pixels;
	size_t width, height;
};
struct GtkData {
	std::string title;
	Data _data;
	Glib::RefPtr<Gtk::Application> app;

	GtkData(std::string name = "", size_t w = 0, size_t h = 0, uint32_t *pixels = nullptr): title(name)  {
		_data.pixels = pixels;
		_data.height = h;
		_data.width = w;
		app = Gtk::Application::create("gtkmm.render", Gio::APPLICATION_FLAGS_NONE);
	}
	int run();
};
# else
#  include <stddef.h>
#  include <gtk/gtk.h>
#  include <stdint.h>

typedef struct _GtkData {
	char *title;
	size_t width;
	size_t height;
	GtkApplication *app;
	uint32_t *pixels;
} *GtkData;

GtkData gtk_data_new(char *title, size_t width, size_t height, uint32_t *pixels);
int gtk_app_run(GtkData data, int argc, char **argv);
# endif
#endif

#ifdef USE_GL
int gl_render(uint32_t *pixels, size_t width, size_t height, char *title);
#endif // USE_GL

#endif // !OLIVES_H
