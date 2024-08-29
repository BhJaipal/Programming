#ifndef ALOO_STYLE_H
#define ALOO_STYLE_H
#include "types.h"

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
 * @brief Gets classes of widget
 */
char **getWidgetClasses(alooWidget *widget);

#endif // ALOO_STYLE_H