#include "app.h"
#include "macros.h"

struct alooApp_Status
CreateApp(char *appName, struct alooAppOptions gAppOptions,
		  void activateFn(GtkApplication *app, gpointer user_data)) {
	GtkApplication *gtkApp;
	int status;

	GApplicationFlags flags;
	switch (gAppOptions.appFlags) {
	case APP_FLAGS_NONE: flags = G_APPLICATION_FLAGS_NONE; break;
	case APP_FLAGS_IS_SERVICE: flags = G_APPLICATION_IS_SERVICE; break;
	case APP_FLAGS_IS_LAUNCHER: flags = G_APPLICATION_IS_LAUNCHER; break;
	default: flags = G_APPLICATION_FLAGS_NONE; break;
	}
	gtkApp = gtk_application_new(appName, flags);
	g_signal_connect(gtkApp, "activate", G_CALLBACK(activateFn), NULL);
	status = g_application_run(G_APPLICATION(gtkApp), gAppOptions.argc,
							   gAppOptions.argv);
	struct alooApp_Status out = {gtkApp, status};

	g_object_unref(gtkApp);
	return out;
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