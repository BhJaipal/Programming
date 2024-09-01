/**
 * @file style.h
 * @author Jaipal001
 * @brief Aloo CSS related functions
 */
#ifndef ALOO_STYLE_H
#define ALOO_STYLE_H
#include "types.h"

/******************** Private Funcs ********************/

/**
 * @brief Import CSS file from path
 * @param name path of css file
 */
void __importCssFromPath(const char *name);
/**
 * @brief Import CSS file from content
 * @param content css content
 * @param length content length
 */
void __importCssFromData(const char *content, gssize length);
/**
 * @brief Import CSS file from content
 * @param file CSS GFile
 */
void __importCssFromFile(GFile *file);

/**
 * @brief Set the Width of widget
 */
alooWidget *__setWidth(alooWidget *wid, int width);
/**
 * @brief Set the Height of widget
 */
alooWidget *__setHeight(alooWidget *wid, int height);
/**
 * @brief Set the Width and Height of widget
 */
alooWidget *__setSize(alooWidget *wid, int width, int height);

/**
 * @brief Adds class to widget
 */
alooWidget *__widgetAddClass(alooWidget *widget, char *class);
/**
 * @brief Removes class from widget
 */
alooWidget *__widgetRemoveClass(alooWidget *widget, char *class);
/**
 * @brief Gets classes of widget
 */
char **g__etWidgetClasses(alooWidget *widget);
/**
 * @brief Sets classes of widget
 */
alooWidget *__setWidgetClasses(alooWidget *widget, char **classes);

/******************** Private Types ********************/

typedef void (*__importCssFromPath_Type)(const char *name);
typedef void (*__importCssFromData_Type)(const char *content, gssize length);
typedef void (*__importCssFromFile_Type)(GFile *file);

typedef alooWidget *(*__setWidth_Type)(alooWidget *wid, int width);
typedef alooWidget *(*__setHeight_Type)(alooWidget *wid, int height);
typedef alooWidget *(*__setSize_Type)(alooWidget *wid, int width, int height);

typedef alooWidget *(*__widgetAddClass_Type)(alooWidget *widget, char *class);
typedef alooWidget *(*__widgetRemoveClass_Type)(alooWidget *widget,
												char *class);
typedef char **(*__getWidgetClasses_Type)(alooWidget *widget);
typedef alooWidget *(*__setWidgetClasses_Type)(alooWidget *widget,
											   char **classes);

struct _alooCSS {
	__importCssFromPath_Type importPath;
	__importCssFromData_Type importData;
	__importCssFromFile_Type importFile;
	__setWidth_Type setWidth;
	__setHeight_Type setHeight;
	__setSize_Type setSize;
	__widgetAddClass_Type addClass;
	__widgetRemoveClass_Type removeClass;
	__getWidgetClasses_Type getClasses;
	__setWidgetClasses_Type setClasses;
};

/******************** Public ********************/

extern struct _alooCSS CSS;

#endif // ALOO_STYLE_H