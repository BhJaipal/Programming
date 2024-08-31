/**
 * @file app.h
 * @author Jaipal001
 * @brief Aloo Application related functions
 */
#ifndef ALOO_APP_H
#define ALOO_APP_H
#include "types.h"
#include <gtk/gtk.h>

/**
 * @brief Returns GtkApplication and status
 */
struct alooApp_Status {
	GtkApplication *app;
	int status;
};

/**
 * @brief G Application Flags
 */
enum alooAppFlags {
	/**
	 * @brief G_APPLICATION_FLAGS_NONE
	 */
	APP_FLAGS_NONE = 0,
	/**
	 * @brief G_APPLICATION_FLAGS_IS_LAUNCHER
	 */
	APP_FLAGS_IS_LAUNCHER,
	/**
	 * @brief G_APPLICATION_FLAGS_IS_SERVICE
	 */
	APP_FLAGS_IS_SERVICE
};

/**
 * @brief Takes GApplicationFlags, argc and argv
 */
struct alooAppOptions {
	enum alooAppFlags appFlags;
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
struct alooApp_Status CreateApp(char *app_id, struct alooAppOptions gAppOptions,
								void activateFn(GtkApplication *app,
												gpointer user_data));

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
 * @brief Set the Window for Application
 */
alooWidget *setWindowApplication(alooWidget *window, GtkApplication *app);

/**
 * @brief Shows Window
 */
void showWindow(alooWidget *window);

#endif // ALOO_APP_H