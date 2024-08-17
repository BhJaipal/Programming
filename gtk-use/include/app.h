#include <gtk/gtk.h>

struct GAppAndStatus {
	GtkApplication *app;
	int status;
};
struct GAppOptions {
	GApplicationFlags GAppFlags;
	int argc;
	char **argv;
};

struct GAppAndStatus CreateApp(char *appName, struct GAppOptions gAppOptions,
							   void activateFn(GtkApplication *app,
											   gpointer user_data));