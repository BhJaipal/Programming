#include "../include/app.h"

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

GObject *alooGetBuilderObject(AlooBuilder *builder, const char *name) {
	return gtk_builder_get_object(builder->builder, name);
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
void unrefBuilder(AlooBuilder *data) { g_object_unref(data->builder); }

AlooBuilder *createBuilder() {
	AlooBuilder *out = malloc(sizeof(AlooBuilder));
	out->builder = gtk_builder_new();
	return out;
}

int builderAddFile(AlooBuilder *build, const char *filename, GError **err) {
	return gtk_builder_add_from_file(build->builder, filename, err);
}
int builderAddContent(AlooBuilder *build, const char *content, gssize length,
					  GError **err) {
	return gtk_builder_add_from_string(build->builder, content, length, err);
}
int builderAddResource(AlooBuilder *build, const char *resource_path,
					   GError **err) {
	return gtk_builder_add_from_resource(build->builder, resource_path, err);
}
