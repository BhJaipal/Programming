#include <gtk/gtk.h>

struct My_GAppAndStatus {
	GtkApplication *app;
	int status;
};
struct My_GAppOptions {
	GApplicationFlags GAppFlags;
	int argc;
	char **argv;
};

struct My_GAppAndStatus
CreateApp(char *appName, struct My_GAppOptions gAppOptions,
		  void activateFn(GtkApplication *app, gpointer user_data));

GtkWidget *My_HorizontalAlign(GtkWidget *widget, GtkAlign alignment);
GtkWidget *My_VerticalAlign(GtkWidget *widget, GtkAlign alignment);

GtkWidget *My_AddEventListener(GtkWidget *widget_instance, char *event_name,
							   GCallback CallbackFn, gpointer data);

GtkWidget *My_SetWindowChild(GtkWidget *window, GtkWidget *child);

GtkWidget *My_PresentWindow(GtkWidget *window);

GtkWidget *My_AddNewButtonLabel(const char *label);

GtkWidget *My_ApplicationNewWindow(GtkApplication *app);

GtkWidget *My_SetWindowTitle(GtkWidget *window, const char *title);

GtkWidget *My_WindowSetSize(GtkWidget *window, int width, int height);
