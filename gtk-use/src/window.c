#include "window.h"
#include "macros.h"
#include "widget.h"

alooWidget *__alooSetWindowChild(alooWidget *window, alooWidget *child) {
	gtk_window_set_child(GTK_WINDOW(window->child), child->child);
	return window;
}
alooWidget *__alooPresentWindow(alooWidget *window) {
	gtk_window_present(GTK_WINDOW(window->child));
	return window;
}

alooWidget *__alooApplicationNewWindow(AlooApplication *app) {
	return Widget.gtk_to_aloo(gtk_application_window_new(app->app));
}
alooWidget *__alooSetWindowTitle(alooWidget *window, const char *title) {
	gtk_window_set_title(GTK_WINDOW(window->child), title);
	return window;
}
alooWidget *__setWindowSize(alooWidget *window, int width, int height) {
	gtk_window_set_default_size(GTK_WINDOW(window->child), width, height);
	return window;
}

alooWidget *__setWindowApplication(alooWidget *window, AlooApplication *app) {
	gtk_window_set_application(GTK_WINDOW(window->child), app->app);
}

void __showWindow(alooWidget *window) {
	if (!ALOO_IS_WINDOW(window)) {
		fprintf(stderr, "Widget is not a window\n");
	} else {
		gtk_widget_show(window->child);
	}
}

alooWidget *__app_add_window(AlooApplication *app, alooWidget *window) {
	gtk_application_add_window(app->app, GTK_WINDOW(window->child));
}

struct _alooWindow Window = {.new = __alooApplicationNewWindow,
							 .present = __alooPresentWindow,
							 .show = __showWindow,
							 .setChild = __alooSetWindowChild,
							 .setTitle = __alooSetWindowTitle,
							 .setSize = __setWindowSize,
							 .app_add_window = __app_add_window,
							 .set_app_window = __setWindowApplication};
