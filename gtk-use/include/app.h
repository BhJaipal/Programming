#ifndef ALOO_APP_H
#define ALOO_APP_H
#include "types.h"
#include <gtk/gtk.h>

/**
 * @brief Returns GtkApplication and status
 */
struct alooAppAndStatus {
	GtkApplication *app;
	int status;
};
/**
 * @brief Takes GApplicationFlags, argc and argv
 *
 */
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

/**
 * @brief Sets horizontal alignment of alooWidget
 */
alooWidget *alooHorizontalAlign(alooWidget *widget, GtkAlign alignment);
/**
 * @brief Sets vertical alignment of alooWidget
 */
alooWidget *alooVerticalAlign(alooWidget *widget, GtkAlign alignment);

/**
 * @brief Adds event listener to a widget
 * @param widget_instance
 * @param data parameters for event listener
 */
alooWidget *alooAddEventListener(alooWidget *widget_instance, char *event_name,
								 GCallback CallbackFn, gpointer data);

/**
 * @brief Sets Window child
 *
 * @param window
 * @param child
 * @return GtkWidget*
 */
GtkWidget *alooSetWindowChild(GtkWidget *window, GtkWidget *child);

/**
 * @brief Presents GtkWindow
 *
 * @param window
 * @return GtkWidget*
 */
GtkWidget *alooPresentWindow(GtkWidget *window);

/**
 * @brief Create new GtkButton
 */
GtkWidget *alooAddNewButtonLabel(const char *label);

/**
 * @brief Create a GtkWindow
 */
GtkWidget *alooApplicationNewWindow(GtkApplication *app);

/**
 * @brief Sets GtkWindow title
 */
GtkWidget *alooSetWindowTitle(GtkWidget *window, const char *title);

/**
 * @brief Sets aloo Window size
 */
alooWidget *setWindowSize(alooWidget *window, int width, int height);

/**
 * @brief Gets GObject from builder
 */
GObject *alooGetBuilderObject(GtkBuilder *builder, const char *name);

alooWidget *setWindowApplication(alooWidget *window, GtkApplication *app);

#endif // ALOO_APP_H