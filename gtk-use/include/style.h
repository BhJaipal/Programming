/**
 * @file style.h
 * @author Jaipal001 (@BhJaipal)
 * @brief Aloo CSS related functions
 */
#ifndef ALOO_STYLE_H
#define ALOO_STYLE_H
#include "types.h"

/**
 * @brief Import CSS file from path
 * @param name path of css file
 */
void importCssFromPath(const char *name);
/**
 * @brief Import CSS file from content
 * @param content css content
 * @param length content length
 */
void importCssFromData(const char *content, gssize length);
/**
 * @brief Import CSS file from content
 * @param file CSS GFile
 */
void importCssFromFile(GFile *file);

/**
 * @brief Set the Width of widget
 */
alooWidget *setWidth(alooWidget *wid, int width);
/**
 * @brief Set the Height of widget
 */
alooWidget *setHeight(alooWidget *wid, int height);
/**
 * @brief Set the Width and Height of widget
 */
alooWidget *setSize(alooWidget *wid, int width, int height);

/**
 * @brief Adds class to widget
 */
alooWidget *widgetAddClass(alooWidget *widget, char *class);
/**
 * @brief Removes class from widget
 */
alooWidget *widgetRemoveClass(alooWidget *widget, char *class);
/**
 * @brief Gets classes of widget
 */
char **getWidgetClasses(alooWidget *widget);
/**
 * @brief Sets classes of widget
 */
alooWidget *setWidgetClasses(alooWidget *widget, char **classes);

#endif // ALOO_STYLE_H