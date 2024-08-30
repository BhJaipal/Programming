#ifndef ALOO_WIDGET_H
#define ALOO_WIDGET_H
#include "types.h"
#include <gtk/gtk.h>

/**
 * @brief Creates alooWidget from GtkWidget
 */
alooWidget *GTK_TO_ALOO(GtkWidget *widget);

/**
 * @brief Create alooWidget from GObject
 */
alooWidget *OBJECT_TO_ALOO(GObject *obj);

/**
 * @brief Creates GtkWidget from builder
 */
GtkWidget *OBJECT_TO_GTK_WIDGET(AlooBuilder *builder, const char *name);

/**
 * @brief Creates alooWidget from builder
 */
alooWidget *alooWidgetFromBuilder(AlooBuilder *builder, const char *name);

/**
 * @brief Sets orientation of alooWidget
 */
alooWidget *alooSetOrientation(alooWidget *widget, GtkOrientation orien);

/**
 * @brief Create a widget
 * @param type type of widget
 * @param child actual GtkWidget
 * @return alooWidget*
 */
alooWidget *NewWidget(WidgetType type, GtkWidget *child);

/**
 * @brief Set the Name of widget
 * @param widget alooWidget
 * @param name string for name of widget
 * @return returns the widget
 */
alooWidget *setWidgetName(alooWidget *widget, const char *name);

#endif // ALOO_WIDGET_H