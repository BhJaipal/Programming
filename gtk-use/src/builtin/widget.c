#include "builtin/widget.h"
#include "builtin/macros.h"
#include <gtk/gtk.h>

GtkWidget *__WidtoGtk(alooWidget *wid) { return wid->child; }

alooWidget *__NewWidget(WidgetType type, GtkWidget *child) {
	alooWidget *widget = malloc(sizeof(alooWidget));
	widget->child = child;
	widget->type = type;
	return widget;
}

alooWidget *__OBJECT_TO_ALOO(GObject *obj) {
	WidgetType type;
	GtkWidget *widget = GTK_WIDGET(obj);
	if (GTK_IS_BOX(widget)) {
		type = ALOO_BOX;
	} else if (GTK_IS_GRID(widget)) {
		type = ALOO_GRID;
	} else if (GTK_IS_BUTTON(widget)) {
		type = ALOO_BUTTON;
	} else if (GTK_IS_LABEL(widget)) {
		type = ALOO_LABEL;
	} else if (GTK_IS_WINDOW(widget)) {
		type = ALOO_WINDOW;
	} else {
		type = ALOO_NEW_WIDGET;
	}
	alooWidget *wid = malloc(sizeof(alooWidget));
	wid->child = widget;
	wid->type = type;
	return wid;
}

alooWidget *__GTK_TO_ALOO(GtkWidget *widget) {
	WidgetType type;
	if (GTK_IS_BOX(widget)) {
		type = ALOO_BOX;
	} else if (GTK_IS_GRID(widget)) {
		type = ALOO_GRID;
	} else if (GTK_IS_BUTTON(widget)) {
		type = ALOO_BUTTON;
	} else if (GTK_IS_LABEL(widget)) {
		type = ALOO_LABEL;
	} else {
		type = ALOO_NEW_WIDGET;
	}
	alooWidget *wid = malloc(sizeof(alooWidget));
	wid->child = widget;
	wid->type = type;
	return wid;
}

GtkWidget *__OBJECT_TO_GTK_WIDGET(AlooBuilder *builder, const char *name) {
	return GTK_WIDGET(gtk_builder_get_object(builder->builder, name));
}
alooWidget *__alooHorizontalAlign(alooWidget *widget, GtkAlign alignment) {
	gtk_widget_set_halign(widget->child, alignment);
	return widget;
}
alooWidget *__alooVerticalAlign(alooWidget *widget, GtkAlign alignment) {
	gtk_widget_set_valign(widget->child, alignment);
	return widget;
}
alooWidget *__alooSetOrientation(alooWidget *widget, GtkOrientation orien) {
	gtk_orientable_set_orientation(GTK_ORIENTABLE(widget->child), orien);
	return widget;
}

alooWidget *__setWidgetName(alooWidget *widget, const char *name) {
	gtk_widget_set_name(Widget.to_gtk(widget), name);
	return widget;
}

alooWidget *__alooAddEventListener(alooWidget *widget_instance,
								   char *event_name, GCallback CallbackFn,
								   gpointer data) {
	g_signal_connect(widget_instance->child, event_name, G_CALLBACK(CallbackFn),
					 data);
	return widget_instance;
}

int is_widget_of_type(alooWidget *widget, enum WidgetType type) {

	GType checker;
	if (type == ALOO_BOX) {
		checker = GTK_TYPE_BOX;
	} else if (type == ALOO_BUTTON) {
		checker = GTK_TYPE_BUTTON;
	} else if (type == ALOO_GRID) {
		checker = GTK_TYPE_GRID;
	} else if (type == ALOO_LABEL) {
		checker = GTK_TYPE_LABEL;
	} else {
		checker = GTK_TYPE_WINDOW;
	}
	return ((widget->type == type || widget->type == ALOO_NEW_WIDGET) &&
			G_TYPE_CHECK_INSTANCE_TYPE((widget->child), checker));
}

int __isBox(alooWidget *wid) { return is_widget_of_type(wid, ALOO_BOX); }
int __isButton(alooWidget *wid) { return is_widget_of_type(wid, ALOO_BUTTON); }
int __isGrid(alooWidget *wid) { return is_widget_of_type(wid, ALOO_GRID); }
int __isLabel(alooWidget *wid) { return is_widget_of_type(wid, ALOO_LABEL); }
int __isWindow(alooWidget *wid) { return is_widget_of_type(wid, ALOO_WINDOW); }

struct _aloo_widget Widget = {
	.new = __NewWidget,
	.gtk_to_aloo = __GTK_TO_ALOO,
	.obj_to_aloo = __OBJECT_TO_ALOO,
	.setName = __setWidgetName,
	.setOrientation = __alooSetOrientation,
	.obj_to_gtk = __OBJECT_TO_GTK_WIDGET,
	.verticalAlign = __alooVerticalAlign,
	.horizontalAlign = __alooHorizontalAlign,
	.addEventListener = __alooAddEventListener,
	.check =
		{
			.isBox = __isBox,
			.isButton = __isButton,
			.isGrid = __isGrid,
			.isLabel = __isLabel,
			.isWindow = __isWindow,
		},
	.to_gtk = __WidtoGtk,
};