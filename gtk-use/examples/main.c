#include "../include/aloo.h"
#include <gdk/gdk.h>
#include <gtk/gtk.h>

alooWidget *labelGrid;
alooWidget *navbar;
alooWidget *navMenu;
alooWidget *nothingLabel = 0;
int isNothing = 1;

struct _labelList {
	alooWidget *labels[10];
	int len;
} labelList;

static void toggleNav() {
	char **classes = getWidgetClasses(navbar);

	if (!strcmp(classes[0], "vertical")) {
		widgetRemoveClass(navMenu, "nav-menu-show");
		widgetAddClass(navMenu, "nav-menu-hidden");
		classes[0] = "horizontal";
	} else {
		widgetRemoveClass(navMenu, "nav-menu-hidden");
		widgetAddClass(navMenu, "nav-menu-show");
		classes[0] = "vertical";
	}
	setWidgetClasses(navbar, classes);
}

void nothingHappened(alooWidget *data);

void print_hello() {
	if (labelList.len == 9) {
		nothingLabel = newLabel("Maximum number of labels reached");
		setWidgetName(nothingLabel, "no-label");
		isNothing = 1;
		gridAttach(labelGrid, nothingLabel, 1, 4, 3, 1);
		return;
	}

	if (isNothing && nothingLabel != 0) nothingHappened(labelGrid);
	alooWidget *label = newLabel("Hello World");
	setWidgetName(label, "label");
	gridAttach(labelGrid, label, (labelList.len / 3) + 1,
			   (labelList.len % 3) + 1, 1, 1);
	labelList.labels[labelList.len] = label;
	labelList.len++;
}
void removeLabel() {
	if (labelList.len == 9) {
		gridRemove(labelGrid, nothingLabel);
		nothingLabel = 0;
		isNothing = 0;
	}
	if (isNothing && nothingLabel != 0) return;
	if (labelList.len == 0) {
		isNothing = 0;
		nothingHappened(labelGrid);
		return;
	}
	gridRemove(labelGrid, labelList.labels[labelList.len - 1]);
	alooWidget *label = labelList.labels[labelList.len - 1];
	labelList.len--;
}
void nothingHappened(alooWidget *data) {
	if (isNothing) {
		gridRemove(data, nothingLabel);
		nothingLabel = 0;
		isNothing = 0;
	} else {
		nothingLabel = newLabel("Nothing Happened");
		setWidgetName(nothingLabel, "no-label");
		gridAttach(data, nothingLabel, 1, 1, 2, 1);
		isNothing = 1;
	}
}

static void activate(GtkApplication *app, gpointer user_data) {
	labelList.len = 0;

	GtkBuilder *builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "builder.ui", NULL);
	alooWidget *appBody = alooWidgetFromBuilder(builder, "app");
	alooWidget *box = alooWidgetFromBuilder(builder, "box");
	alooWidget *window = alooWidgetFromBuilder(builder, "gtk-window");
	GObject *addButton = alooGetBuilderObject(builder, "add");
	GObject *rmLabel = alooGetBuilderObject(builder, "remove");
	alooWidget *grid = alooWidgetFromBuilder(builder, "grid");
	navbar = alooWidgetFromBuilder(builder, "navbar");
	alooWidget *menuBar = alooWidgetFromBuilder(builder, "menu-bar");
	alooWidget *boxBody = alooWidgetFromBuilder(builder, "box-body");

	alooSetOrientation(box, GTK_ORIENTATION_VERTICAL);
	alooSetOrientation(navbar, GTK_ORIENTATION_VERTICAL);
	alooSetOrientation(appBody, GTK_ORIENTATION_VERTICAL);
	alooSetOrientation(boxBody, GTK_ORIENTATION_HORIZONTAL);
	alooWidget *buttonWidget = OBJECT_TO_ALOO(addButton);
	alooWidget *rmLabelWidget = OBJECT_TO_ALOO(rmLabel);
	setSize(buttonWidget, 100, 50);
	setSize(rmLabelWidget, 125, 50);

	// gtk_widget_set_visible(GTK_WINDOW(window), TRUE);
	// gtk_window_fullscreen(GTK_WINDOW(window));
	setWindowSize(window, 1200, 600);
	setWindowApplication(window, app);
	alooAddEventListener(buttonWidget, "clicked", print_hello, NULL);
	alooAddEventListener(rmLabelWidget, "clicked", removeLabel, NULL);

	labelGrid = alooGridNew();
	setWidgetName(labelGrid, "label-grid");
	alooHorizontalAlign(alooVerticalAlign(labelGrid, GTK_ALIGN_CENTER),
						GTK_ALIGN_CENTER);
	alooHorizontalAlign(alooVerticalAlign(box, GTK_ALIGN_CENTER),
						GTK_ALIGN_CENTER);
	boxAppend(box, labelGrid);

	alooVerticalAlign(alooHorizontalAlign(grid, GTK_ALIGN_CENTER),
					  GTK_ALIGN_START);

	GtkCssProvider *cssProvider = gtk_css_provider_new();
	gtk_css_provider_load_from_path(cssProvider, "style.css");
	gtk_style_context_add_provider_for_display(
		gdk_display_get_default(), GTK_STYLE_PROVIDER(cssProvider),
		GTK_STYLE_PROVIDER_PRIORITY_USER);

	setGridColumnSpacing(grid, 20);
	setGridRowSpacing(labelGrid, 5);
	setGridColumnSpacing(labelGrid, 5);

	alooAddEventListener(menuBar, "clicked", toggleNav, NULL);

	navMenu = alooGridNew();
	setWidgetName(navMenu, "nav-menu");
	const char *menus[] = {"File", "Edit", "Save"};
	for (int i = 0; i < 3; i++) {
		alooWidget *label = newButtonWithLabel(menus[i]);
		setWidgetName(label, "menu-opt");
		setSize(label, 100, 20);
		gridAttach(navMenu, label, 0, i, 1, 1);
	}
	setSize(box, 1100, 600);
	setSize(navMenu, 100, 600);
	widgetAddClass(navMenu, "nav-menu-show");
	setSize(alooWidgetFromBuilder(builder, "nav-show"), 1200, 70);
	char **classes = getWidgetClasses(navMenu);
	for (int i = 0; i < sizeof(classes) / sizeof(classes[0]); i++) {
		printf("%s\n", classes[i]);
	}

	boxPrepend(boxBody, navMenu);

	showWindow(window);
	g_object_unref(builder);
}

int main(int argc, char **argv) {
	struct alooAppOptions opts = {G_APPLICATION_FLAGS_NONE, argc, argv};
	struct alooAppAndStatus appOut =
		CreateApp("com.test.hello", opts, activate);
	return 0;
}
