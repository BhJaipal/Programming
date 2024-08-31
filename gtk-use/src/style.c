#include "style.h"
#include "macros.h"

void importCssFromPath(const char *path) {
	GtkCssProvider *cssProvider = gtk_css_provider_new();
	gtk_css_provider_load_from_path(cssProvider, path);
	gtk_style_context_add_provider_for_display(
		gdk_display_get_default(), GTK_STYLE_PROVIDER(cssProvider),
		GTK_STYLE_PROVIDER_PRIORITY_USER);
}
void importCssFromData(const char *content, gssize length) {
	GtkCssProvider *cssProvider = gtk_css_provider_new();
	gtk_css_provider_load_from_data(cssProvider, content, length);
	gtk_style_context_add_provider_for_display(
		gdk_display_get_default(), GTK_STYLE_PROVIDER(cssProvider),
		GTK_STYLE_PROVIDER_PRIORITY_USER);
}
void importCssFromFile(GFile *file) {
	GtkCssProvider *cssProvider = gtk_css_provider_new();
	gtk_css_provider_load_from_file(cssProvider, file);
	gtk_style_context_add_provider_for_display(
		gdk_display_get_default(), GTK_STYLE_PROVIDER(cssProvider),
		GTK_STYLE_PROVIDER_PRIORITY_USER);
}

alooWidget *setWidth(alooWidget *wid, int width) {
	gtk_widget_set_size_request(wid->child, width, -1);
	return wid;
}
alooWidget *setHeight(alooWidget *wid, int height) {
	gtk_widget_set_size_request(wid->child, -1, height);
	return wid;
}
alooWidget *setSize(alooWidget *wid, int width, int height) {
	gtk_widget_set_size_request(wid->child, width, height);
	return wid;
}

alooWidget *widgetAddClass(alooWidget *widget, char *class) {
	gtk_widget_add_css_class(ALOO_WIDGET_TO_GTK(widget), class);
	return widget;
}

alooWidget *widgetRemoveClass(alooWidget *widget, char *class) {
	gtk_widget_remove_css_class(ALOO_WIDGET_TO_GTK(widget), class);
	return widget;
}
char **getWidgetClasses(alooWidget *widget) {
	return gtk_widget_get_css_classes(ALOO_WIDGET_TO_GTK(widget));
}
alooWidget *setWidgetClasses(alooWidget *widget, char **classes) {
	gtk_widget_set_css_classes(ALOO_WIDGET_TO_GTK(widget),
							   (const char **)classes);
}
