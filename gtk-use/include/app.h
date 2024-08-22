#include <gtk/gtk.h>

struct myGAppAndStatus {
	GtkApplication *app;
	int status;
};
struct myGAppOptions {
	GApplicationFlags GAppFlags;
	int argc;
	char **argv;
};

struct myGAppAndStatus
CreateApp(char *appName, struct myGAppOptions gAppOptions,
		  void activateFn(GtkApplication *app, gpointer user_data));

GtkWidget *myHorizontalAlign(GtkWidget *widget, GtkAlign alignment);
GtkWidget *myVerticalAlign(GtkWidget *widget, GtkAlign alignment);

GtkWidget *myAddEventListener(GtkWidget *widget_instance, char *event_name,
							  GCallback CallbackFn, gpointer data);

GtkWidget *mySetWindowChild(GtkWidget *window, GtkWidget *child);

GtkWidget *myPresentWindow(GtkWidget *window);

GtkWidget *myAddNewButtonLabel(const char *label);

GtkWidget *myApplicationNewWindow(GtkApplication *app);

GtkWidget *mySetWindowTitle(GtkWidget *window, const char *title);

GtkWidget *myWindowSetSize(GtkWidget *window, int width, int height);

GObject *myGetBuilderObject(GtkBuilder *builder, const char *name);