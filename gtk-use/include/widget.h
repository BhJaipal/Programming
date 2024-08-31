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

/******************** Private Types ********************/

typedef alooWidget *(*GTK_TO_ALOO_Type)(GtkWidget *widget);

typedef alooWidget *(*OBJECT_TO_ALOO_Type)(GObject *obj);

typedef alooWidget *(*alooSetOrientation_Type)(alooWidget *widget,
											   GtkOrientation orien);

typedef alooWidget *(*NewWidget_Type)(WidgetType type, GtkWidget *child);

typedef alooWidget *(*setWidgetName_Type)(alooWidget *widget, const char *name);

typedef GtkWidget *(*__OBJECT_TO_GTK_WIDGET_Type)(AlooBuilder *builder,
												  const char *name);

typedef alooWidget *(*__alooVerticalAlign_Type)(alooWidget *widget,
												GtkAlign alignment);
typedef alooWidget *(*__alooHorizontalAlign_Type)(alooWidget *widget,
												  GtkAlign alignment);

typedef alooWidget *(*__alooAddEventListener_Type)(alooWidget *widget_instance,
												   char *event_name,
												   GCallback CallbackFn,
												   gpointer data);

/******************** Public ********************/

struct _aloo_widget {
	/// @brief Creates GtkWidget from builder
	__OBJECT_TO_GTK_WIDGET_Type obj_to_gtk;
	/// @brief Create alooWidget from GObject
	OBJECT_TO_ALOO_Type obj_to_aloo;
	/// @brief Creates alooWidget from GtkWidget
	GTK_TO_ALOO_Type gtk_to_aloo;
	/// @brief Sets orientation of alooWidget
	alooSetOrientation_Type setOrientation;
	/// @brief Create a widget
	/// @param type type of widget
	/// @param child actual GtkWidget
	/// @return alooWidget*
	NewWidget_Type new;
	/// @brief Set the Name of widget
	/// @param widget alooWidget
	/// @param name string for name of widget
	/// @return returns the widget
	setWidgetName_Type setName;
	/// @brief Sets horizontal alignment of alooWidget
	__alooHorizontalAlign_Type horizontalAlign;
	/// @brief Sets vertical alignment of alooWidget
	__alooVerticalAlign_Type verticalAlign;
	/// @brief Adds event listener to a widget
	/// @param widget_instance
	/// @param data parameters for event listener
	__alooAddEventListener_Type addEventListener;
};

extern struct _aloo_widget Widget;

#endif // ALOO_WIDGET_H