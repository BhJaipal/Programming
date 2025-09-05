#define USE_GTK
#include "olive.h"
#include "gdkmm/general.h"
#include "glibmm/refptr.h"
#include "gtkmm/drawingarea.h"
#include "gtkmm/window.h"
#include <cstddef>
#include <cstdint>
#include <string>


class MyDrawing : public Gtk::DrawingArea {
	Data data;
public:
	MyDrawing(Data data) {
		this->data = data;
	}
	bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) {
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
		return 1;
	}
};
int GtkData::run() {
	Gtk::Window window;
	window.set_title(title);
	MyDrawing area(_data);
	window.add(area);
	window.show_all();
	return app->run(window);
}
