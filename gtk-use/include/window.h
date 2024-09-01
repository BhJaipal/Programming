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

typedef alooWidget *(*__alooSetWindowChild_Type)(alooWidget *window,
												 alooWidget *child);

typedef alooWidget *(*__alooPresentWindow_Type)(alooWidget *window);

typedef alooWidget *(*__alooApplicationNewWindow_Type)(AlooApplication *app);

typedef alooWidget *(*__alooSetWindowTitle_Type)(alooWidget *window,
												 const char *title);

typedef alooWidget *(*__setWindowSize_Type)(alooWidget *window, int width,
											int height);

typedef alooWidget *(*__setWindowApplication_Type)(alooWidget *window,
												   AlooApplication *app);
typedef alooWidget *(*__app_add_window_Type)(AlooApplication *app,
											 alooWidget *window);
typedef void (*__showWindow_Type)(alooWidget *window);

struct _alooWindow {
	/// @brief Create a GtkWindow
	/// @param app AlooApplication*
	/// @return alooWidget*
	__alooApplicationNewWindow_Type new;
	/// @brief Presents GtkWindow
	/// @param window alooWidget*
	/// @return alooWidget*
	__alooPresentWindow_Type present;
	/// @brief Sets Window child
	/// @param window alooWidget *
	/// @param child alooWidget *
	/// @return
	__alooSetWindowChild_Type setChild;
	/// @brief Sets GtkWindow title
	/// @param window alooWidget *
	/// @param title const char*
	/// @return alooWidget *
	__alooSetWindowTitle_Type setTitle;
	/// @brief Sets aloo Window size
	/// @param window alooWidget *
	/// @param width int
	/// @param height int
	/// @return alooWidget*
	__setWindowSize_Type setSize;
	/// @brief Set the Window for Application
	/// @param window alooWidget*
	/// @param app AlooApplication*
	/// @return alooWidget*
	__setWindowApplication_Type set_app_window;
	/// @brief Adds Window to Application
	/// @param app AlooApplication*
	/// @param window alooWidget*
	/// @return aloowidget*
	__app_add_window_Type app_add_window;
	/// @brief Shows Window
	/// @param window alooWidget*
	/// @return void
	__showWindow_Type show;
};

/******************** Public ********************/

extern struct _alooWindow Window;

#endif // ALOO_WINDOW_H