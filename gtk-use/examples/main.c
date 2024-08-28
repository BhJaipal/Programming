#include "../include/aloo.h"
#include <gdk/gdk.h>
#include <gtk/gtk.h>

GtkWidget *labelGrid;
alooWidget *navbar;
GtkWidget *navMenu;
GtkWidget *nothingLabel = 0;
int isNothing = 1;
struct _labelList {
	GtkWidget *labels[10];
	int len;
} labelList;

static void toggleNav() {
	const char **classes =
		(const char **)gtk_widget_get_css_classes(navbar->child);

	if (!strcmp(classes[0], "vertical")) {
		gtk_widget_remove_css_class(navMenu, "nav-menu-show");
		gtk_widget_add_css_class(navMenu, "nav-menu-hidden");
		classes[0] = "horizontal";
	} else {
		gtk_widget_remove_css_class(navMenu, "nav-menu-hidden");
		gtk_widget_add_css_class(navMenu, "nav-menu-show");
		classes[0] = "vertical";
	}
	gtk_widget_set_css_classes(navbar->child, classes);
}

void nothingHappened(GtkWidget *data);

void print_hello() {
	if (labelList.len == 9) {
		nothingLabel = gtk_label_new("Maximum number of labels reached");
		gtk_widget_set_name(nothingLabel, "no-label");
		isNothing = 1;
		gtk_grid_attach(GTK_GRID(labelGrid), nothingLabel, 1, 4, 3, 1);
		return;
	}

	if (isNothing && nothingLabel != 0) nothingHappened(labelGrid);
	GtkWidget *label = gtk_label_new("Hello World");
	gtk_widget_set_name(label, "label");
	// gtk_box_append(GTK_BOX(box), label);
	gtk_grid_attach(GTK_GRID(labelGrid), label, (labelList.len / 3) + 1,
					(labelList.len % 3) + 1, 1, 1);
	// labelList.labels =
	// realloc(labelList.labels, sizeof(GtkWidget *) + (labelList.len + 1));
	labelList.labels[labelList.len] = label;
	labelList.len++;
}
void removeLabel() {
	if (labelList.len == 9) {
		gtk_grid_remove(GTK_GRID(labelGrid), nothingLabel);
		nothingLabel = 0;
		isNothing = 0;
	}
	if (isNothing && nothingLabel != 0) return;
	if (labelList.len == 0) {
		isNothing = 0;
		nothingHappened(labelGrid);
		return;
	}
	gtk_grid_remove(GTK_GRID(labelGrid), labelList.labels[labelList.len - 1]);
	GtkWidget *label = labelList.labels[labelList.len - 1];
	// gtk_box_remove(GTK_BOX(box), label);
	labelList.len--;
}
void nothingHappened(GtkWidget *data) {
	if (isNothing) {
		gtk_grid_remove(GTK_GRID(data), nothingLabel);
		nothingLabel = 0;
		isNothing = 0;
	} else {
		nothingLabel = gtk_label_new("Nothing Happened");
		gtk_widget_set_name(nothingLabel, "no-label");
		gtk_grid_attach(GTK_GRID(data), nothingLabel, 1, 1, 2, 1);
		isNothing = 1;
	}
}

static void activate(GtkApplication *app, gpointer user_data) {
	// labelList.labels = malloc(sizeof(GtkWidget *) * 0);
	labelList.len = 0;

	GtkBuilder *builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "examples/builder.ui", NULL);
	alooWidget *appBody = alooWidgetFromBuilder(builder, "app");
	alooWidget *box = alooWidgetFromBuilder(builder, "box");
	alooWidget *window = alooWidgetFromBuilder(builder, "gtk-window");
	GObject *addButton = alooGetBuilderObject(builder, "add");
	GObject *rmLabel = alooGetBuilderObject(builder, "remove");
	GtkWidget *grid = OBJECT_TO_GTK_WIDGET(builder, "grid");
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
	gtk_window_set_default_size(GTK_WINDOW(window->child), 1200, 600);
	gtk_window_set_application(GTK_WINDOW(window->child), app);
	alooAddEventListener(buttonWidget, "clicked", print_hello, NULL);
	alooAddEventListener(rmLabelWidget, "clicked", removeLabel, NULL);

	labelGrid = gtk_grid_new();
	gtk_widget_set_name(labelGrid, "label-grid");
	alooHorizontalAlign(
		alooVerticalAlign(GTK_TO_ALOO(labelGrid), GTK_ALIGN_CENTER),
		GTK_ALIGN_CENTER);
	alooHorizontalAlign(alooVerticalAlign(box, GTK_ALIGN_CENTER),
						GTK_ALIGN_CENTER);
	gtk_box_append(GTK_BOX(GTK_WIDGET(box)), labelGrid);

	alooVerticalAlign(alooHorizontalAlign(GTK_TO_ALOO(grid), GTK_ALIGN_CENTER),
					  GTK_ALIGN_START);

	GtkCssProvider *cssProvider = gtk_css_provider_new();
	gtk_css_provider_load_from_path(cssProvider, "examples/style.css");
	gtk_style_context_add_provider_for_display(
		gdk_display_get_default(), GTK_STYLE_PROVIDER(cssProvider),
		GTK_STYLE_PROVIDER_PRIORITY_USER);

	gtk_grid_set_column_spacing(GTK_GRID(grid), 20);
	gtk_grid_set_row_spacing(GTK_GRID(labelGrid), 5);
	gtk_grid_set_column_spacing(GTK_GRID(labelGrid), 5);

	alooAddEventListener(menuBar, "clicked", toggleNav, NULL);

	navMenu = gtk_grid_new();
	gtk_widget_set_name(navMenu, "nav-menu");
	const char *menus[] = {"File", "Edit", "Save"};
	for (int i = 0; i < 3; i++) {
		GtkWidget *label = gtk_button_new();
		gtk_button_set_label(GTK_BUTTON(label), menus[i]);
		gtk_widget_set_name(label, "menu-opt");
		gtk_widget_set_size_request(GTK_WIDGET(label), 100, 20);
		gtk_grid_attach(GTK_GRID(navMenu), label, 0, i, 1, 1);
	}
	setSize(box, 1100, 600);
	gtk_widget_set_size_request(GTK_WIDGET(navMenu), 100, 600);
	gtk_widget_add_css_class(navMenu, "nav-menu-show");
	gtk_widget_set_size_request(
		GTK_WIDGET(alooGetBuilderObject(builder, "nav-show")), 1200, 70);
	char **classes = gtk_widget_get_css_classes(navMenu);
	for (int i = 0; i < sizeof(classes) / sizeof(classes[0]); i++) {
		printf("%s\n", classes[i]);
	}

	gtk_box_prepend(GTK_BOX(boxBody->child), navMenu);

	gtk_widget_show(window->child);
	g_object_unref(builder);
}

int main(int argc, char **argv) {
	struct alooAppOptions opts = {G_APPLICATION_FLAGS_NONE, argc, argv};
	struct alooAppAndStatus appOut =
		CreateApp("com.test.hello", opts, activate);
	return 0;
}
