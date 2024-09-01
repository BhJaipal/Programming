#include "app.h"
#include "macros.h"

struct AlooApplication *__CreateApp(const char *appName,
									struct alooAppOptions gAppOptions) {
	GApplicationFlags flags;
	switch (gAppOptions.appFlags) {
	case APP_FLAGS_NONE: flags = G_APPLICATION_FLAGS_NONE; break;
	case APP_FLAGS_IS_SERVICE: flags = G_APPLICATION_IS_SERVICE; break;
	case APP_FLAGS_IS_LAUNCHER: flags = G_APPLICATION_IS_LAUNCHER; break;
	default: flags = G_APPLICATION_FLAGS_NONE; break;
	}
	GtkApplication *gtkApp = gtk_application_new(appName, flags);
	AlooApplication *out = malloc(sizeof(AlooApplication));
	out->app = gtkApp;
	out->status = 0;
	out->argc = gAppOptions.argc;
	out->argv = gAppOptions.argv;
	return out;
}
int __RunApp(AlooApplication *application) {
	GApplication *app = G_APPLICATION(application->app);
	int status = g_application_run(app, application->argc, application->argv);
	application->status = status;
	return status;
}
int __RunAppAndUnrefIt(AlooApplication *application) {
	GApplication *app = G_APPLICATION(application->app);
	int status = g_application_run(app, application->argc, application->argv);
	application->status = status;
	__unrefApp(application);
	return status;
}

void __unrefApp(AlooApplication *application) {
	g_object_unref(application->app);
}
void __AppAddEvents(AlooApplication *app, const char *event,
					void callbackFn()) {
	g_signal_connect(app->app, "activate", G_CALLBACK(callbackFn), NULL);
}
struct _alooApp Application = {
	__CreateApp, __RunApp, __RunAppAndUnrefIt, __unrefApp, __AppAddEvents,
};