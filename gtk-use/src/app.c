#include "../include/app.h"

struct alooAppAndStatus
CreateApp(char *appName, struct alooAppOptions gAppOptions,
		  void activateFn(GtkApplication *app, gpointer user_data)) {
	GtkApplication *gtkApp;
	int status;

	gtkApp = gtk_application_new(appName, gAppOptions.GAppFlags);
	g_signal_connect(gtkApp, "activate", G_CALLBACK(activateFn), NULL);
	status = g_application_run(G_APPLICATION(gtkApp), gAppOptions.argc,
							   gAppOptions.argv);
	g_object_unref(gtkApp);
	struct alooAppAndStatus out = {gtkApp, status};
	return out;
}

alooWidget *alooHorizontalAlign(alooWidget *widget, GtkAlign alignment) {
	gtk_widget_set_halign(widget->child, alignment);
	return widget;
}
alooWidget *alooVerticalAlign(alooWidget *widget, GtkAlign alignment) {
	gtk_widget_set_valign(widget->child, alignment);
	return widget;
}
alooWidget *alooAddEventListener(alooWidget *widget_instance, char *event_name,
								 GCallback CallbackFn, gpointer data) {
	g_signal_connect(widget_instance->child, event_name, G_CALLBACK(CallbackFn),
					 data);
	return widget_instance;
}

GtkWidget *alooSetWindowChild(GtkWidget *window, GtkWidget *child) {
	gtk_window_set_child(GTK_WINDOW(window), child);
	return window;
}
GtkWidget *alooPresentWindow(GtkWidget *window) {
	gtk_window_present(GTK_WINDOW(window));
	return window;
}

GtkWidget *alooAddNewButtonLabel(const char *label) {
	return gtk_button_new_with_label(label);
}
GtkWidget *alooApplicationNewWindow(GtkApplication *app) {
	return gtk_application_window_new(app);
}
GtkWidget *alooSetWindowTitle(GtkWidget *window, const char *title) {
	gtk_window_set_title(GTK_WINDOW(window), title);
	return window;
}
alooWidget *setWindowSize(alooWidget *window, int width, int height) {
	gtk_window_set_default_size(GTK_WINDOW(window->child), width, height);
	return window;
}

GObject *alooGetBuilderObject(GtkBuilder *builder, const char *name) {
	return gtk_builder_get_object(builder, name);
}

alooWidget *setWindowApplication(alooWidget *window, GtkApplication *app) {
	gtk_window_set_application(GTK_WINDOW(window->child), app);
}

void showWindow(alooWidget *window) {
	if (!ALOO_IS_WINDOW(window)) {
		fprintf(stderr, "Widget is not a window\n");
	} else {
		gtk_widget_show(window->child);
	}
}
