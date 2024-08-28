#ifndef ALOO_APP_H
#define ALOO_APP_H
#include "types.h"
#include <gtk/gtk.h>

struct alooAppAndStatus {
	GtkApplication *app;
	int status;
};
struct alooAppOptions {
	GApplicationFlags GAppFlags;
	int argc;
	char **argv;
};

/**
 * @brief Create a App object
 * @param app_id App Id are like com.google.Chrome, dev.zed.Zed
 * @param gAppOptions It takes GApplicationFlags, argc and argv
 * @param activateFn static void function which will be called when app is
 * started
 * @return It returns GtkApplication and status
 */
struct alooAppAndStatus
CreateApp(char *app_id, struct alooAppOptions gAppOptions,
		  void activateFn(GtkApplication *app, gpointer user_data));

alooWidget *alooHorizontalAlign(alooWidget *widget, GtkAlign alignment);
alooWidget *alooVerticalAlign(alooWidget *widget, GtkAlign alignment);

alooWidget *alooAddEventListener(alooWidget *widget_instance, char *event_name,
								 GCallback CallbackFn, gpointer data);

GtkWidget *alooSetWindowChild(GtkWidget *window, GtkWidget *child);

GtkWidget *alooPresentWindow(GtkWidget *window);

GtkWidget *alooAddNewButtonLabel(const char *label);

GtkWidget *alooApplicationNewWindow(GtkApplication *app);

GtkWidget *alooSetWindowTitle(GtkWidget *window, const char *title);

GtkWidget *alooWindowSetSize(GtkWidget *window, int width, int height);

GObject *alooGetBuilderObject(GtkBuilder *builder, const char *name);

#endif // ALOO_APP_H