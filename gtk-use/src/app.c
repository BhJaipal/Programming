#include "../include/app.h"

struct myGAppAndStatus
CreateApp(char *appName, struct myGAppOptions gAppOptions,
		  void activateFn(GtkApplication *app, gpointer user_data)) {
	GtkApplication *gtkApp;
	int status;

	gtkApp = gtk_application_new(appName, gAppOptions.GAppFlags);
	g_signal_connect(gtkApp, "activate", G_CALLBACK(activateFn), NULL);
	status = g_application_run(gtkApp, gAppOptions.argc, gAppOptions.argv);
	g_object_unref(gtkApp);
	struct myGAppAndStatus out = {gtkApp, status};
	return out;
}

GtkWidget *myHorizontalAlign(GtkWidget *widget, GtkAlign alignment) {
	gtk_widget_set_halign(widget, alignment);
	return widget;
}
GtkWidget *myVerticalAlign(GtkWidget *widget, GtkAlign alignment) {
	gtk_widget_set_valign(widget, alignment);
	return widget;
}
GtkWidget *myAddEventListener(GtkWidget *widget_instance, char *event_name,
							  GCallback CallbackFn, gpointer data) {
	g_signal_connect(widget_instance, event_name, G_CALLBACK(CallbackFn), data);
	return widget_instance;
}

GtkWidget *mySetWindowChild(GtkWidget *window, GtkWidget *child) {
	gtk_window_set_child(GTK_WINDOW(window), child);
	return window;
}
GtkWidget *myPresentWindow(GtkWidget *window) {
	gtk_window_present(GTK_WINDOW(window));
	return window;
}

GtkWidget *myAddNewButtonLabel(const char *label) {
	return gtk_button_new_with_label(label);
}
GtkWidget *myApplicationNewWindow(GtkApplication *app) {
	return gtk_application_window_new(app);
}
GtkWidget *mySetWindowTitle(GtkWidget *window, const char *title) {
	gtk_window_set_title(GTK_WINDOW(window), title);
	return window;
}
GtkWidget *myWindowSetSize(GtkWidget *window, int width, int height) {
	gtk_window_set_default_size(GTK_WINDOW(window), width, height);
	return window;
}

GObject *myGetBuilderObject(GtkBuilder *builder, const char *name) {
	return gtk_builder_get_object(builder, name);
}
