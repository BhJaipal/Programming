#define USE_GTK
#include "../olive.h"
#include "demo-data.h"
uint32_t pixels[HEIGHT * WIDTH];

int main(int c, char **v) {
	setup();
	GtkData data = gtk_data_new("Cairo renderer", WIDTH, HEIGHT, pixels);
	return gtk_app_run(data, c, v);
}
