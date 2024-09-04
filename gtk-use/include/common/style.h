/**
 * @file style.h
 * @author Jaipal001
 * @brief Aloo CSS related functions
 */
#ifndef ALOO_STYLE_H
#define ALOO_STYLE_H
#include "types.h"

/******************** Private Funcs ********************/

/// @brief Import CSS file from path
/// @param name path of css file
void __importCssFromPath(const char *name);
/// @brief Import CSS file from content
/// @param content css content
/// @param length content length
void __importCssFromData(const char *content, gssize length);
/// @brief Import CSS file from content
/// @param file CSS GFile
void __importCssFromFile(GFile *file);

/** @brief Set the Width of widget */
alooWidget *__setWidth(alooWidget *wid, int width);
/** @brief Set the Height of widget */
alooWidget *__setHeight(alooWidget *wid, int height);
/** @brief Set the Width and Height of widget */
alooWidget *__setSize(alooWidget *wid, int width, int height);

/** @brief Adds class to widget */
alooWidget *__widgetAddClass(alooWidget *widget, char *class);
/** @brief Removes class from widget */
alooWidget *__widgetRemoveClass(alooWidget *widget, char *class);
/** @brief Gets classes of widget */
char **g__etWidgetClasses(alooWidget *widget);
/** @brief Sets classes of widget */
alooWidget *__setWidgetClasses(alooWidget *widget, char **classes);

/******************** Private Types ********************/

struct _alooCSS {
	/// @brief Import CSS file from path
	/// @param name path of css file
	void (*importPath)(const char *name);
	/// @brief Import CSS file from content
	/// @param content css content
	/// @param length content length
	void (*importData)(const char *content, gssize length);
	/// @brief Import CSS file from content
	/// @param file CSS GFile
	void (*importFile)(GFile *file);
	/** @brief Set the Width of widget */
	alooWidget *(*setWidth)(alooWidget *wid, int width);
	/** @brief Set the Height of widget */
	alooWidget *(*setHeight)(alooWidget *wid, int height);
	/** @brief Set the Width and Height of widget */
	alooWidget *(*setSize)(alooWidget *wid, int width, int height);
	/** @brief Adds class to widget */
	alooWidget *(*addClass)(alooWidget *widget, char *class);
	/** @brief Removes class from widget */
	alooWidget *(*removeClass)(alooWidget *widget, char *class);
	/** @brief Gets classes of widget */
	char **(*getClasses)(alooWidget *widget);
	/** @brief Sets classes of widget */
	alooWidget *(*setClasses)(alooWidget *widget, char **classes);
};

/******************** Public ********************/

extern struct _alooCSS CSS;

#endif // ALOO_STYLE_H