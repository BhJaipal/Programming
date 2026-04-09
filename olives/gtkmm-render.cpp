#include "gdkmm/general.h"
#include "gtkmm/drawingarea.h"
#include "gtkmm/window.h"
#include "olive.h"
#include "sigc++/functors/mem_fun.h"
#include <cstddef>

GtkData global_data;

class MyDrawing : public Gtk::DrawingArea {
public:
	MyDrawing() {
		set_draw_func(sigc::mem_fun(*this, &MyDrawing::on_draw));
	}
	void on_draw(const Cairo::RefPtr<Cairo::Context>& cr, int width, int height) {
		Data data = global_data._data;
		for (size_t i = 0; i < data.width * data.height; i++) {
			Gdk::RGBA color;
			color.set_rgba(
				(double)((data.pixels[i] >> 16) & 0xff) / 255,
				(double)((data.pixels[i] >> 8) & 0xff) / 255,
				(double)(data.pixels[i] & 0xff)/255
			);

			Gdk::Cairo::set_source_rgba(cr, color);
			cr->rectangle(i % data.width, (size_t)((float)i / data.width), 1.5, 1.5);
			cr->fill();
		}
	}
};

class MyWindow: public Gtk::Window {
	MyDrawing m_area;
public:
	MyWindow() {
		set_title(global_data.title);
		set_child(m_area);
	}
};

int GtkData::run(int c, char **v) {
	global_data = *this;
	return app->make_window_and_run<MyWindow>(c, v);
}
