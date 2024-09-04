#include "common/style.h"
#include "common/macros.h"
#include "common/widget.h"

void __importCssFromPath(const char *path) {
	GtkCssProvider *cssProvider = gtk_css_provider_new();
	gtk_css_provider_load_from_path(cssProvider, path);
	gtk_style_context_add_provider_for_display(
		gdk_display_get_default(), GTK_STYLE_PROVIDER(cssProvider),
		GTK_STYLE_PROVIDER_PRIORITY_USER);
}
void __importCssFromData(const char *content, gssize length) {
	GtkCssProvider *cssProvider = gtk_css_provider_new();
	gtk_css_provider_load_from_data(cssProvider, content, length);
	gtk_style_context_add_provider_for_display(
		gdk_display_get_default(), GTK_STYLE_PROVIDER(cssProvider),
		GTK_STYLE_PROVIDER_PRIORITY_USER);
}
void __importCssFromFile(GFile *file) {
	GtkCssProvider *cssProvider = gtk_css_provider_new();
	gtk_css_provider_load_from_file(cssProvider, file);
	gtk_style_context_add_provider_for_display(
		gdk_display_get_default(), GTK_STYLE_PROVIDER(cssProvider),
		GTK_STYLE_PROVIDER_PRIORITY_USER);
}

alooWidget *__setWidth(alooWidget *wid, int width) {
	gtk_widget_set_size_request(wid->child, width, -1);
	return wid;
}
alooWidget *__setHeight(alooWidget *wid, int height) {
	gtk_widget_set_size_request(wid->child, -1, height);
	return wid;
}
alooWidget *__setSize(alooWidget *wid, int width, int height) {
	gtk_widget_set_size_request(wid->child, width, height);
	return wid;
}

alooWidget *__widgetAddClass(alooWidget *widget, char *class) {
	gtk_widget_add_css_class(Widget.to_gtk(widget), class);
	return widget;
}

alooWidget *__widgetRemoveClass(alooWidget *widget, char *class) {
	gtk_widget_remove_css_class(Widget.to_gtk(widget), class);
	return widget;
}
char **__getWidgetClasses(alooWidget *widget) {
	return gtk_widget_get_css_classes(Widget.to_gtk(widget));
}
alooWidget *__setWidgetClasses(alooWidget *widget, char **classes) {
	gtk_widget_set_css_classes(Widget.to_gtk(widget), (const char **)classes);
	return widget;
}

struct _alooCSS CSS = {
	.importData = __importCssFromData,
	.importFile = __importCssFromFile,
	.importPath = __importCssFromPath,
	.addClass = __widgetAddClass,
	.removeClass = __widgetRemoveClass,
	.setClasses = __setWidgetClasses,
	.getClasses = __getWidgetClasses,
	.setSize = __setSize,
	.setHeight = __setHeight,
	.setWidth = __setWidth,
};