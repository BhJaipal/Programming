#include "../include/app.h"

struct My_GAppAndStatus
CreateApp(char *appName, struct My_GAppOptions gAppOptions,
		  void activateFn(GtkApplication *app, gpointer user_data)) {
	GtkApplication *gtkApp;
	int status;

	gtkApp = gtk_application_new(appName, gAppOptions.GAppFlags);
	g_signal_connect(gtkApp, "activate", G_CALLBACK(activateFn), NULL);
	status = g_application_run(gtkApp, gAppOptions.argc, gAppOptions.argv);
	g_object_unref(gtkApp);
	struct My_GAppAndStatus out = {gtkApp, status};
	return out;
}

GtkWidget *My_HorizontalAlign(GtkWidget *widget, GtkAlign alignment) {
	gtk_widget_set_halign(widget, alignment);
	return widget;
}
GtkWidget *My_VerticalAlign(GtkWidget *widget, GtkAlign alignment) {
	gtk_widget_set_valign(widget, alignment);
	return widget;
}
GtkWidget *My_AddEventListener(GtkWidget *widget_instance, char *event_name,
							   GCallback CallbackFn, gpointer data) {
	g_signal_connect(widget_instance, event_name, G_CALLBACK(CallbackFn), data);
	return widget_instance;
}

GtkWidget *My_SetWindowChild(GtkWidget *window, GtkWidget *child) {
	gtk_window_set_child(GTK_WINDOW(window), child);
	return window;
}
GtkWidget *My_PresentWindow(GtkWidget *window) {
	gtk_window_present(GTK_WINDOW(window));
	return window;
}

GtkWidget *My_AddNewButtonLabel(const char *label) {
	return gtk_button_new_with_label(label);
}
GtkWidget *My_ApplicationNewWindow(GtkApplication *app) {
	return gtk_application_window_new(app);
}
GtkWidget *My_SetWindowTitle(GtkWidget *window, const char *title) {
	gtk_window_set_title(GTK_WINDOW(window), title);
	return window;
}
GtkWidget *My_WindowSetSize(GtkWidget *window, int width, int height) {
	gtk_window_set_default_size(GTK_WINDOW(window), width, height);
	return window;
}