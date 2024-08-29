#include "../include/widget.h"

alooWidget *NewWidget(WidgetType type, GtkWidget *child) {
	alooWidget *widget = malloc(sizeof(alooWidget));
	widget->child = child;
	widget->type = type;
	return widget;
}

alooWidget *OBJECT_TO_ALOO(GObject *obj) {
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
	} else {
		type = ALOO_NEW_WIDGET;
	}
	alooWidget *wid = malloc(sizeof(alooWidget));
	wid->child = widget;
	wid->type = type;
	return wid;
}

alooWidget *GTK_TO_ALOO(GtkWidget *widget) {
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

GtkWidget *OBJECT_TO_GTK_WIDGET(GtkBuilder *builder, const char *name) {
	return GTK_WIDGET(gtk_builder_get_object(builder, name));
}

alooWidget *alooWidgetFromBuilder(GtkBuilder *builder, const char *name) {
	return OBJECT_TO_ALOO(gtk_builder_get_object(builder, name));
}

alooWidget *alooSetOrientation(alooWidget *widget, GtkOrientation orien) {
	gtk_orientable_set_orientation(GTK_ORIENTABLE(widget->child), orien);
	return widget;
}

alooWidget *setWidgetName(alooWidget *widget, const char *name) {
	gtk_widget_set_name(ALOO_WIDGET_TO_GTK(widget), name);
	return widget;
}
