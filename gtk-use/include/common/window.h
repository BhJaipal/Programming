/**
 * @file window.h
 * @author Jaipal001
 * @brief Contains aloo Window related functions
 */

#ifndef ALOO_WINDOW_H
#define ALOO_WINDOW_H
#include "app.h"
#include "types.h"

/******************** Private Funcs ********************/

/**
 * @brief Sets Window child
 */
alooWidget *__alooSetWindowChild(alooWidget *window, alooWidget *child);

/**
 * @brief Presents GtkWindow
 */
alooWidget *__alooPresentWindow(alooWidget *window);

/**
 * @brief Create a GtkWindow
 */
alooWidget *__alooApplicationNewWindow(AlooApplication *app);

/**
 * @brief Sets GtkWindow title
 */
alooWidget *__alooSetWindowTitle(alooWidget *window, const char *title);

/**
 * @brief Sets aloo Window size
 */
alooWidget *__setWindowSize(alooWidget *window, int width, int height);

/**
 * @brief Set the Window for Application
 */
alooWidget *__setWindowApplication(alooWidget *window, AlooApplication *app);

/**
 * @brief Adds Window to Application
 */
alooWidget *__app_add_window(AlooApplication *app, alooWidget *window);

/**
 * @brief Shows Window
 */
void __showWindow(alooWidget *window);

/******************** Private Types ********************/

struct _alooWindow {
	/// @brief Create a GtkWindow
	/// @param app AlooApplication*
	/// @return alooWidget*
	alooWidget *(*new)(AlooApplication *app);
	/// @brief Presents GtkWindow
	/// @param window alooWidget*
	/// @return alooWidget*
	alooWidget *(*present)(alooWidget *window);
	/// @brief Sets Window child
	/// @param window alooWidget *
	/// @param child alooWidget *
	/// @return
	alooWidget *(*setChild)(alooWidget *window, alooWidget *child);
	/// @brief Sets GtkWindow title
	/// @param window alooWidget *
	/// @param title const char*
	/// @return alooWidget *
	alooWidget *(*setTitle)(alooWidget *window, const char *title);
	/// @brief Sets aloo Window size
	/// @param window alooWidget *
	/// @param width int
	/// @param height int
	/// @return alooWidget*
	alooWidget *(*setSize)(alooWidget *window, int width, int height);
	/// @brief Set the Window for Application
	/// @param window alooWidget*
	/// @param app AlooApplication*
	/// @return alooWidget*
	alooWidget *(*set_app_window)(alooWidget *window, AlooApplication *app);
	/// @brief Adds Window to Application
	/// @param app AlooApplication*
	/// @param window alooWidget*
	/// @return aloowidget*
	alooWidget *(*app_add_window)(AlooApplication *app, alooWidget *window);
	/// @brief Shows Window
	/// @param window alooWidget*
	/// @return void
	void (*show)(alooWidget *window);
};

/******************** Public ********************/

extern struct _alooWindow Window;

#endif // ALOO_WINDOW_H