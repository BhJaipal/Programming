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

typedef struct AlooApplication {
	GtkApplication *app;
	int status;
	int argc;
	char **argv;
} AlooApplication;

/**
 * @brief Takes GApplicationFlags, argc and argv
 */
struct alooAppOptions {
	enum alooAppFlags appFlags;
	int argc;
	char **argv;
};

/******************** Private Funcs ********************/

/**
 * @brief Create a App object
 * @param app_id App Id are like com.google.Chrome, dev.zed.Zed
 * @param gAppOptions It takes GApplicationFlags, argc and argv
 * @return It returns Aloo Application
 */
AlooApplication *__CreateApp(const char *app_id,
							 struct alooAppOptions gAppOptions);

/// @brief Runs aloo App
/// @return status on exiting app
int __RunApp(AlooApplication *application);
/// @brief Runs aloo App and unrefs after exiting it
/// @return status on exiting app
int __RunAppAndUnrefIt(AlooApplication *application);
/** @brief unrefs aloo App */
void __unrefApp(AlooApplication *application);
/**
 * @brief Adds Event Listener to Aloo App
 * @param app Aloo Application
 * @param event Event name
 * @param callbackFn static void function which will be called when app is
 * started
 */
void __AppAddEvents(AlooApplication *app, const char *event, void callbackFn());

/******************** Private Types ********************/

struct _alooApp {
	/// @brief Create a App object
	/// @param app_id App Id are like com.google.Chrome, dev.zed.Zed
	/// @param gAppOptions It takes GApplicationFlags, argc and argv
	/// @return It returns Aloo Application
	AlooApplication *(*create)(const char *app_id,
							   struct alooAppOptions gAppOptions);
	/// @brief Runs aloo App
	/// @return status on exiting app
	int (*run)(AlooApplication *application);
	/// @brief Runs aloo App and unrefs after exiting it
	/// @return status on exiting app
	int (*run_and_unref)(AlooApplication *application);
	/** @brief unrefs aloo App */
	void (*unref)(AlooApplication *application);
	/// @brief Adds Event Listener to Aloo App
	/// @param app Aloo Application
	/// @param event Event name
	/// @param callbackFn static void function which will be called when app is
	/// started
	void (*add_event_listener)(AlooApplication *app, const char *event,
							   void callbackFn());
};

/******************** Public ********************/

extern struct _alooApp Application;

#endif // ALOO_APP_H