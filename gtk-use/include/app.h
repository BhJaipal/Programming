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
 * @brief generates app options with APP_FLAGS_NONE
 */
#define NONE_FLAGS_OPTIONS(argc, argv)                                         \
	{ APP_FLAGS_NONE, argc, argv }
/**
 * @brief generates app options with APP_FLAGS_IS_LAUNCHER
 */
#define LAUNCHER_FLAGS_OPTIONS(argc, argv)                                     \
	{ APP_FLAGS_IS_LAUNCHER, argc, argv }
/**
 * @brief generates app options with APP_FLAGS_IS_SERVICE
 */
#define SERVICE_FLAGS_OPTIONS(argc, argv)                                      \
	{ APP_FLAGS_IS_SERVICE, argc, argv }

#define ALOO_IS_WINDOW(X) GTK_IS_WINDOW(X->child)

/**
 * @brief Create a App object
 * @param app_id App Id are like com.google.Chrome, dev.zed.Zed
 * @param appOptions It takes GApplicationFlags, argc and argv
 * @param activateFn static void function which will be called when app is
 * started
 * @return It returns GtkApplication and status
 */
struct alooApp_Status CreateApp(char *app_id, struct alooAppOptions gAppOptions,
								void activateFn(GtkApplication *app,
												gpointer user_data));

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
GObject *alooGetBuilderObject(AlooBuilder *builder, const char *name);

/**
 * @brief Set the Window for Application
 */
alooWidget *setWindowApplication(alooWidget *window, GtkApplication *app);

/**
 * @brief Shows Window
 */
void showWindow(alooWidget *window);

/**
 * @brief Unrefs aloo builder
 */
void unrefBuilder(AlooBuilder *data);

/**
 * @brief Create a Builder object
 * @return AlooBuilder*
 */
AlooBuilder *createBuilder();

/**
 * @brief Adds a file with builder
 * @param build AlooBuilder object
 * @param filename UI file path with name
 * @param err Error handler, Default `NULL`
 */
int builderAddFile(AlooBuilder *build, const char *filename, GError **err);

/**
 * @brief Adds a file with builder
 * @param build AlooBuilder object
 * @param content UI data
 * @param length UI data length
 * @param err Error handler, Default `NULL`
 */
int builderAddContent(AlooBuilder *build, const char *content, gssize length,
					  GError **err);

/**
 * @brief Adds a file with builder
 * @param build AlooBuilder object
 * @param resource_path UI resource path
 * @param err Error handler, Default `NULL`
 */
int builderAddResource(AlooBuilder *build, const char *resource_path,
					   GError **err);

#endif // ALOO_APP_H