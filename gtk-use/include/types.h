#ifndef ALOO_TYPES_H
#define ALOO_TYPES_H
#include <gtk/gtk.h>

typedef enum WidgetType {
	/**
	 * @brief Used for Gtk Box
	 */
	ALOO_BOX,
	/**
	 * @brief Used for Gtk Grid
	 */
	ALOO_GRID,
	/**
	 * @brief Used for Gtk Row
	 */
	ALOO_ROW,
	/**
	 * @brief Used for Gtk Column
	 */
	ALOO_COLUMN,
	/**
	 * @brief Used for Gtk Button
	 */
	ALOO_BUTTON,
	/**
	 * @brief Used for Gtk Label
	 */
	ALOO_LABEL,
	/**
	 * @brief Can be used to create new custom widget and used with all
	 */
	ALOO_NEW_WIDGET
} WidgetType;

/**
 * @brief widget for my aloo library
 */
typedef struct alooWidget {
	/**
	 * @brief actual GtkWidget
	 */
	GtkWidget *child;
	/**
	 * @brief Type of widget
	 */
	WidgetType type;
} alooWidget;

#define ALOO_WIDGET_TO_GTK(x) x->child
#endif // ALOO_TYPES_H