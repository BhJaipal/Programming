/**
 * @file widget.h
 * @author Jaipal001
 * @brief Aloo Widget related functions
 */
#ifndef ALOO_WIDGET_H
#define ALOO_WIDGET_H
#include "types.h"
#include <gtk/gtk.h>

/******************** Private Funcs ********************/

/**
 * @brief Creates alooWidget from GtkWidget
 */
alooWidget *__GTK_TO_ALOO(GtkWidget *widget);

/**
 * @brief Create alooWidget from GObject
 */
alooWidget *__OBJECT_TO_ALOO(GObject *obj);

/**
 * @brief Sets orientation of alooWidget
 */
alooWidget *__alooSetOrientation(alooWidget *widget, GtkOrientation orien);

/**
 * @brief Create a widget
 * @param type type of widget
 * @param child actual GtkWidget
 * @return alooWidget*
 */
alooWidget *__NewWidget(WidgetType type, GtkWidget *child);

/**
 * @brief Set the Name of widget
 * @param widget alooWidget
 * @param name string for name of widget
 * @return returns the widget
 */
alooWidget *__setWidgetName(alooWidget *widget, const char *name);

/**
 * @brief Creates GtkWidget from builder
 */
GtkWidget *__OBJECT_TO_GTK_WIDGET(AlooBuilder *builder, const char *name);

/**
 * @brief Sets horizontal alignment of alooWidget
 */
alooWidget *__alooHorizontalAlign(alooWidget *widget, GtkAlign alignment);
/**
 * @brief Sets vertical alignment of alooWidget
 */
alooWidget *__alooVerticalAlign(alooWidget *widget, GtkAlign alignment);

/**
 * @brief Adds event listener to a widget
 * @param widget_instance
 * @param event_name Event name
 * @param CallbackFn Event Callback function
 * @param data parameters for event listener
 */
alooWidget *__alooAddEventListener(alooWidget *widget_instance,
								   char *event_name, GCallback CallbackFn,
								   gpointer data);

int __isBox(alooWidget *wid);
int __isButton(alooWidget *wid);
int __isGrid(alooWidget *wid);
int __isLabel(alooWidget *wid);
int __isWindow(alooWidget *wid);
GtkWidget *__WidtoGtk(alooWidget *wid);

/******************** Private Types ********************/

struct _aloo_widget {
	/// @brief Creates GtkWidget from builder
	GtkWidget *(*obj_to_gtk)(AlooBuilder *builder, const char *name);
	/// @brief Create alooWidget from GObject
	alooWidget *(*obj_to_aloo)(GObject *obj);
	/// @brief Creates alooWidget from GtkWidget
	alooWidget *(*gtk_to_aloo)(GtkWidget *widget);
	/// @brief Sets orientation of alooWidget
	alooWidget *(*setOrientation)(alooWidget *widget, GtkOrientation orien);
	/// @brief Create a widget
	/// @param type type of widget
	/// @param child actual GtkWidget
	/// @return alooWidget*
	alooWidget *(*new)(WidgetType type, GtkWidget *child);
	/// @brief Set the Name of widget
	/// @param widget alooWidget
	/// @param name string for name of widget
	/// @return returns the widget
	alooWidget *(*setName)(alooWidget *widget, const char *name);
	/// @brief Sets horizontal alignment of alooWidget
	alooWidget *(*horizontalAlign)(alooWidget *widget, GtkAlign alignment);
	/// @brief Sets vertical alignment of alooWidget
	alooWidget *(*verticalAlign)(alooWidget *widget, GtkAlign alignment);
	/// @brief Adds event listener to a widget
	/// @param widget_instance
	/// @param data parameters for event listener
	alooWidget *(*addEventListener)(alooWidget *widget_instance,
									char *event_name, GCallback CallbackFn,
									gpointer data);
	struct {
		int (*isBox)(alooWidget *wid);
		int (*isButton)(alooWidget *wid);
		int (*isGrid)(alooWidget *wid);
		int (*isLabel)(alooWidget *wid);
		int (*isWindow)(alooWidget *wid);
	} check;
	GtkWidget *(*to_gtk)(alooWidget *wid);
};

/******************** Public ********************/

extern struct _aloo_widget Widget;

int is_widget_of_type(alooWidget *widget, enum WidgetType type);

#endif // ALOO_WIDGET_H