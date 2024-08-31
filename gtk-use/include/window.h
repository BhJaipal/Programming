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
	__alooApplicationNewWindow_Type new;
	__alooPresentWindow_Type present;
	__alooSetWindowChild_Type setChild;
	__alooSetWindowTitle_Type setTitle;
	__setWindowSize_Type setSize;
	__setWindowApplication_Type set_app_window;
	__app_add_window_Type app_add_window;
	__showWindow_Type show;
};

/******************** Public ********************/

extern struct _alooWindow Window;

#endif // ALOO_WINDOW_H