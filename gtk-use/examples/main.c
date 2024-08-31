#include "../include/aloo.h"
#include <gtk/gtk.h>

alooWidget *labelGrid;
alooWidget *navbar;
alooWidget *navMenu;
alooWidget *nothingLabel = 0;
AlooApplication *app;
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
		nothingLabel = Label.new("Maximum number of labels reached");
		Widget.setName(nothingLabel, "no-label");
		isNothing = 1;
		Grid.attach(labelGrid, nothingLabel, 1, 4, 3, 1);
		return;
	}

	if (isNothing && nothingLabel != 0) nothingHappened(labelGrid);
	alooWidget *label = Label.new("Hello World");
	Widget.setName(label, "label");
	Grid.attach(labelGrid, label, (labelList.len / 3) + 1,
				(labelList.len % 3) + 1, 1, 1);
	labelList.labels[labelList.len] = label;
	labelList.len++;
}
void removeLabel() {
	if (labelList.len == 9) {
		Grid.remove(labelGrid, nothingLabel);
		nothingLabel = 0;
		isNothing = 0;
	}
	if (isNothing && nothingLabel != 0) return;
	if (labelList.len == 0) {
		isNothing = 0;
		nothingHappened(labelGrid);
		return;
	}
	Grid.remove(labelGrid, labelList.labels[labelList.len - 1]);
	alooWidget *label = labelList.labels[labelList.len - 1];
	labelList.len--;
}
void nothingHappened(alooWidget *data) {
	if (isNothing) {
		Grid.remove(data, nothingLabel);
		nothingLabel = 0;
		isNothing = 0;
	} else {
		nothingLabel = Label.new("Nothing Happened");
		Widget.setName(nothingLabel, "no-label");
		Grid.attach(data, nothingLabel, 1, 1, 2, 1);
		isNothing = 1;
	}
}

static void activate(AlooApplication *app) {
	labelList.len = 0;
	AlooBuilder *builder = Builder.create();
	Builder.addFile(builder, "builder.ui", NULL);
	alooWidget *appBody = Builder.alooFromBuilder(builder, "app");
	alooWidget *box = Builder.alooFromBuilder(builder, "box");
	alooWidget *window = Builder.alooFromBuilder(builder, "gtk-window");
	alooWidget *buttonWidget = Builder.alooFromBuilder(builder, "add");
	alooWidget *rmLabelWidget = Builder.alooFromBuilder(builder, "remove");
	alooWidget *grid = Builder.alooFromBuilder(builder, "button-grid");
	navbar = Builder.alooFromBuilder(builder, "navbar");
	alooWidget *menuBar = Builder.alooFromBuilder(builder, "menu-bar");
	alooWidget *boxBody = Builder.alooFromBuilder(builder, "box-body");

	Widget.setOrientation(box, GTK_ORIENTATION_VERTICAL);
	Widget.setOrientation(navbar, GTK_ORIENTATION_VERTICAL);
	Widget.setOrientation(appBody, GTK_ORIENTATION_VERTICAL);
	Widget.setOrientation(boxBody, GTK_ORIENTATION_HORIZONTAL);
	setSize(buttonWidget, 100, 50);
	setSize(rmLabelWidget, 125, 50);

	// gtk_widget_set_visible(GTK_WINDOW(window), TRUE);
	// gtk_window_fullscreen(GTK_WINDOW(window));
	Window.setSize(window, 1200, 600);
	Window.set_app_window(window, app);
	Widget.addEventListener(buttonWidget, "clicked", print_hello, NULL);
	Widget.addEventListener(rmLabelWidget, "clicked", removeLabel, NULL);

	labelGrid = Grid.new();
	Widget.setName(labelGrid, "label-grid");
	Widget.horizontalAlign(Widget.verticalAlign(labelGrid, GTK_ALIGN_CENTER),
						   GTK_ALIGN_CENTER);
	Widget.horizontalAlign(Widget.verticalAlign(box, GTK_ALIGN_CENTER),
						   GTK_ALIGN_CENTER);
	Box.append(box, labelGrid);

	Widget.horizontalAlign(Widget.verticalAlign(grid, GTK_ALIGN_CENTER),
						   GTK_ALIGN_CENTER);

	importCssFromPath("style.css");

	Grid.column_spacing(grid, 20);
	Grid.row_spacing(labelGrid, 5);
	Grid.column_spacing(labelGrid, 5);

	Widget.addEventListener(menuBar, "clicked", toggleNav, NULL);

	navMenu = Grid.new();
	Widget.setName(navMenu, "nav-menu");
	const char *menus[] = {"File", "Edit", "Save"};
	for (int i = 0; i < 3; i++) {
		alooWidget *label = Button.newWithLabel(menus[i]);
		Widget.setName(label, "menu-opt");
		setSize(label, 100, 20);
		Grid.attach(navMenu, label, 0, i, 1, 1);
	}
	setSize(box, 1100, 600);
	setSize(navMenu, 100, 600);
	widgetAddClass(navMenu, "nav-menu-show");
	setSize(Builder.alooFromBuilder(builder, "nav-show"), 1200, 70);
	char **classes = getWidgetClasses(navMenu);
	for (int i = 0; i < sizeof(classes) / sizeof(classes[0]); i++) {
		printf("%s\n", classes[i]);
	}

	Box.prepend(boxBody, navMenu);

	Window.show(window);
	Builder.unref(builder);
}

int main(int argc, char **argv) {
	struct alooAppOptions opts = NONE_FLAGS_OPTIONS(argc, argv);
	app = Application.create("com.test.hello", opts);
	Application.add_event_listener(app, "activate", activate);
	int status = Application.run(app);
	Application.unref(app);
	return status;
}
