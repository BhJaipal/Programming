#include "../include/app.h"
#include <gtk/gtk.h>

static void print_hello(GtkWidget *widget, gpointer data) {
	g_print("Hello World\n");
}

static void activate(GtkApplication *app, gpointer user_data) {
	GtkWidget *window;
	GtkWidget *button;

	window = gtk_application_window_new(app);
	gtk_window_set_title(GTK_WINDOW(window), "Hello");
	gtk_window_set_default_size(GTK_WINDOW(window), 200, 200);

	button = gtk_button_new_with_label("Hello World");
	gtk_widget_set_halign(button, GTK_ALIGN_CENTER);
	gtk_widget_set_valign(button, GTK_ALIGN_CENTER);

	g_signal_connect(button, "clicked", G_CALLBACK(print_hello), NULL);
	gtk_window_set_child(GTK_WINDOW(window), button);

	gtk_window_present(GTK_WINDOW(window));
}

int main(int argc, char **argv) {
	struct GAppOptions opts = {G_APPLICATION_FLAGS_NONE, argc, argv};
	struct GAppAndStatus appOut = CreateApp("com.test.hello", opts, activate);
	return appOut.status;
}
