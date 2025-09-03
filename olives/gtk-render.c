#define USE_GTK
#include "olive.h"
#include <gtk/gtk.h>
#include <stdlib.h>

void activate(GtkApplication *app, gpointer data);
GtkData gtk_data_new(char *title, size_t width, size_t height, uint32_t *pixels) {
	GtkData data = malloc(sizeof(struct _GtkData));
	GtkApplication *app = gtk_application_new("cairo.draw", G_APPLICATION_FLAGS_NONE);

	data->app = app;
	data->title = malloc(sizeof(title));
	strcpy(data->title, title);
	data->height = height;
	data->width = width;
	data->pixels = pixels;
	g_signal_connect(app, "activate", G_CALLBACK(activate), data);
	return data;
}
void draw(GtkDrawingArea *drawing_area,
				cairo_t			*cr,
				int             width,
				int             height,
				gpointer        user_data);
int gtk_app_run(GtkData data, int argc, char **argv) {
	return g_application_run(G_APPLICATION(data->app), argc, argv);
}
void activate(GtkApplication *app, gpointer data) {
	GtkData app_data = data;
	GtkWidget *window = gtk_application_window_new(app);
	gtk_window_set_default_size(GTK_WINDOW(window), app_data->width, app_data->height);
	gtk_window_set_title(GTK_WINDOW(window), app_data->title);

	GtkWidget *drawing_area = gtk_drawing_area_new();
	gtk_widget_set_size_request (drawing_area, app_data->width, app_data->height);
	gtk_drawing_area_set_draw_func(GTK_DRAWING_AREA(drawing_area), draw, app_data, NULL);

	gtk_window_set_child(GTK_WINDOW(window), drawing_area);
	gtk_widget_show(window);
	gtk_window_present(GTK_WINDOW(window));
}
void draw(GtkDrawingArea *drawing_area,
				cairo_t			*cr,
				int             width,
				int             height,
				gpointer        user_data) {
	GtkData data = user_data;

	for (size_t i = 0; i < data->width * data->height; i++) {
		GdkRGBA color = {
			(double)((data->pixels[i] >> 16) & 0xff) / 255,
			(double)((data->pixels[i] >> 8) & 0xff) / 255,
			(double)(data->pixels[i] & 0xff)/255, 1};

		gdk_cairo_set_source_rgba(cr, &color);
		cairo_rectangle(cr, i % data->width, (size_t)((float)i / data->width), 1.5, 1.5);
		cairo_fill(cr);
	}
}
