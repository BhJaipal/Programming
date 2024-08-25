#include <gtk/gtk.h>

struct alluAppAndStatus {
	GtkApplication *app;
	int status;
};
struct alluAppOptions {
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
struct alluAppAndStatus
CreateApp(char *app_id, struct alluAppOptions gAppOptions,
		  void activateFn(GtkApplication *app, gpointer user_data));

GtkWidget *alluHorizontalAlign(GtkWidget *widget, GtkAlign alignment);
GtkWidget *alluVerticalAlign(GtkWidget *widget, GtkAlign alignment);

GtkWidget *alluAddEventListener(GtkWidget *widget_instance, char *event_name,
								GCallback CallbackFn, gpointer data);

GtkWidget *alluSetWindowChild(GtkWidget *window, GtkWidget *child);

GtkWidget *alluPresentWindow(GtkWidget *window);

GtkWidget *alluAddNewButtonLabel(const char *label);

GtkWidget *alluApplicationNewWindow(GtkApplication *app);

GtkWidget *alluSetWindowTitle(GtkWidget *window, const char *title);

GtkWidget *alluWindowSetSize(GtkWidget *window, int width, int height);

GObject *alluGetBuilderObject(GtkBuilder *builder, const char *name);