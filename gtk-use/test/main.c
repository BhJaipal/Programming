#include "../include/app.h"
#include <gdk/gdk.h>
#include <gtk/gtk.h>

GtkWidget *box;
GtkWidget *labelGrid;
GtkWidget *nothingLabel = 0;
int isNothing = 1;
struct _labelList {
	GtkWidget **labels;
	int len;
} labelList;

void nothingHappened(GObject *data);

void print_hello() {
	if (isNothing && nothingLabel != 0) nothingHappened(box);
	GtkWidget *label = gtk_label_new("Hello World");
	// gtk_box_append(GTK_BOX(box), label);
	gtk_grid_attach(GTK_GRID(labelGrid), label, 1, labelList.len + 1, 1, 1);
	labelList.labels =
		realloc(labelList.labels, sizeof(GtkWidget *) + (labelList.len + 1));
	labelList.labels[labelList.len] = label;
	labelList.len++;
	g_print("Hello World\n");
}
void removeLabel() {
	if (isNothing && nothingLabel != 0) return;
	if (labelList.len == 0) {
		isNothing = 0;
		nothingHappened(box);
		return;
	}
	gtk_grid_remove(GTK_GRID(labelGrid), labelList.labels[labelList.len - 1]);
	GtkWidget *label = labelList.labels[labelList.len - 1];
	// gtk_box_remove(GTK_BOX(box), label);
	labelList.len--;
	g_print("Removed label\n");
}
void nothingHappened(GObject *data) {
	if (isNothing) {
		gtk_box_remove(GTK_BOX(GTK_WIDGET(data)), nothingLabel);
		nothingLabel = 0;
		isNothing = 0;
	} else {
		nothingLabel = gtk_label_new("Nothing Happened");
		gtk_box_append(GTK_BOX(GTK_WIDGET(data)), nothingLabel);
		isNothing = 1;
	}
}

static void activate(GtkApplication *app, gpointer user_data) {
	labelList.labels = malloc(sizeof(GtkWidget *) * 0);
	labelList.len = 0;

	GtkCssProvider *cssProvider = gtk_css_provider_new();
	gtk_css_provider_load_from_path(cssProvider, "test/style.css");
	gtk_style_context_add_provider_for_display(
		gdk_display_get_default(), GTK_STYLE_PROVIDER(cssProvider),
		GTK_STYLE_PROVIDER_PRIORITY_USER);

	GtkBuilder *builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "test/builder.ui", NULL);
	box = GTK_WIDGET(myGetBuilderObject(builder, "box"));
	GtkWidget *window = GTK_WIDGET(myGetBuilderObject(builder, "gtk-window"));
	GObject *button = myGetBuilderObject(builder, "add");
	GObject *rmLabel = myGetBuilderObject(builder, "remove");
	GObject *grid = myGetBuilderObject(builder, "grid");

	gtk_orientable_set_orientation(GTK_ORIENTABLE(box),
								   GTK_ORIENTATION_VERTICAL);
	GtkWidget *buttonWidget = GTK_WIDGET(button);
	GtkWidget *rmLabelWidget = GTK_WIDGET(rmLabel);

	// gtk_widget_set_visible(GTK_WINDOW(window), TRUE);
	gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);
	gtk_window_set_application(GTK_WINDOW(window), app);
	myAddEventListener(buttonWidget, "clicked", print_hello, NULL);
	myAddEventListener(rmLabelWidget, "clicked", removeLabel, NULL);

	myHorizontalAlign(grid, GTK_ALIGN_CENTER);
	myVerticalAlign(grid, GTK_ALIGN_START);
	labelGrid = gtk_grid_new();
	myHorizontalAlign(myVerticalAlign(labelGrid, GTK_ALIGN_CENTER),
					  GTK_ALIGN_CENTER);
	gtk_box_append(GTK_BOX(GTK_WIDGET(box)), labelGrid);

	gtk_widget_show(GTK_WINDOW(window));
	g_object_unref(builder);

	// Without builder
	// GObject *grid = gtk_grid_new();
	// GtkWidget *button, *rmLabel, *window;
	// window = myApplicationNewWindow(app);
	// myWindowSetSize(mySetWindowTitle(window, "Hello Window"), 400, 400);
	// button = myAddNewButtonLabel("Hello World");
	// rmLabel = myAddNewButtonLabel("Remove a label");
	// box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	// GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	// myHorizontalAlign(myVerticalAlign(box, GTK_ALIGN_CENTER),
	// 				   GTK_ALIGN_CENTER);
	// myAddEventListener(button, "clicked", G_CALLBACK(print_hello), box);
	// myAddEventListener(rmLabel, "clicked", G_CALLBACK(removeLabel), box);
	// gtk_grid_attach(GTK_GRID(grid), button, 0, 0, 2, 1);
	// gtk_grid_attach(GTK_GRID(grid), rmLabel, 2, 0, 2, 1);
	// gtk_box_append(GTK_BOX(box), grid);
	// mySetWindowChild(window, box);
	// myPresentWindow(window);
}

int main(int argc, char **argv) {
	struct myGAppOptions opts = {G_APPLICATION_FLAGS_NONE, argc, argv};
	struct myGAppAndStatus appOut = CreateApp("com.test.hello", opts, activate);
	return 0;
}
