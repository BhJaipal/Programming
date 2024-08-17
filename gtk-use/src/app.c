#include "../include/app.h"

struct GAppAndStatus CreateApp(char *appName, struct GAppOptions gAppOptions,
							   void activateFn(GtkApplication *app,
											   gpointer user_data)) {
	GtkApplication *gtkApp;
	int status;

	gtkApp = gtk_application_new(appName, gAppOptions.GAppFlags);
	g_signal_connect(gtkApp, "activate", G_CALLBACK(activateFn), NULL);
	status = g_application_run(gtkApp, gAppOptions.argc, gAppOptions.argv);
	g_object_unref(gtkApp);
	struct GAppAndStatus out = {gtkApp, status};
	return out;
}