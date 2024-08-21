#include "../include/app.h"
#include <gtk/gtk.h>

GtkWidget *box;
GtkWidget *nothingLabel = 0;
int isNothing = 1;
struct _labelList {
	GtkWidget **labels;
	int len;
} labelList;

void nothingHappened(gpointer *data);

static void print_hello(GtkWidget *widget, gpointer data) {
	if (isNothing && nothingLabel != 0) nothingHappened(&data);
	GtkWidget *label = gtk_label_new("Hello World");
	gtk_box_append(GTK_BOX(data), label);
	labelList.labels =
		realloc(labelList.labels, sizeof(GtkWidget *) + (labelList.len + 1));
	labelList.labels[labelList.len] = label;
	labelList.len++;
	g_print("Hello World\n");
}
static void removeLabel(GtkWidget *widget, gpointer data) {
	if (isNothing && nothingLabel != 0) return;
	if (labelList.len == 0) {
		isNothing = 0;
		nothingHappened(&data);
		return;
	}
	GtkWidget *label = labelList.labels[labelList.len - 1];
	gtk_box_remove(GTK_BOX(data), label);
	labelList.len--;
	g_print("Removed label\n");
}
void nothingHappened(gpointer *data) {
	if (isNothing) {
		gtk_box_remove(GTK_BOX(*data), nothingLabel);
		nothingLabel = 0;
		isNothing = 0;
	} else {
		nothingLabel = gtk_label_new("Nothing Happened");
		gtk_box_append(GTK_BOX(*data), nothingLabel);
		isNothing = 1;
	}
}

static void activate(GtkApplication *app, gpointer user_data) {
	labelList.labels = malloc(sizeof(GtkWidget *) * 0);
	labelList.len = 0;
	// GObject *grid = gtk_grid_new();

	GtkBuilder *builder = gtk_builder_new();
	gtk_builder_add_from_file(builder, "./test/builder.ui", NULL);
	GObject *box = gtk_builder_get_object(builder, "box");
	GObject *window = gtk_builder_get_object(builder, "window");
	GObject *button = gtk_builder_get_object(builder, "add");
	GObject *rmLabel = gtk_builder_get_object(builder, "remove");
	GObject *grid = gtk_builder_get_object(builder, "grid");
	gtk_box_set_baseline_position(box, GTK_BASELINE_POSITION_CENTER);
	gtk_window_set_application(GTK_WINDOW(window), app);
	g_signal_connect(button, "clicked", print_hello, box);
	g_signal_connect(rmLabel, "clicked", removeLabel, box);
	gtk_widget_set_visible(GTK_WINDOW(window), TRUE);
	My_VerticalAlign(My_HorizontalAlign(button, GTK_ALIGN_CENTER),
					 GTK_ALIGN_CENTER);
	My_VerticalAlign(My_HorizontalAlign(button, GTK_ALIGN_CENTER),
					 GTK_ALIGN_CENTER);

	// Without builder
	// GtkWidget *button, *rmLabel, *box;
	// window = My_ApplicationNewWindow(app);
	// My_WindowSetSize(My_SetWindowTitle(window, "Hello Window"), 400, 400);
	// button = My_AddNewButtonLabel("Hello World");
	// rmLabel = My_AddNewButtonLabel("Remove a label");
	// box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	// GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
	// My_HorizontalAlign(My_VerticalAlign(box, GTK_ALIGN_CENTER),
	// 				   GTK_ALIGN_CENTER);
	// My_AddEventListener(button, "clicked", G_CALLBACK(print_hello), box);
	// My_AddEventListener(rmLabel, "clicked", G_CALLBACK(removeLabel), box);
	// Without builder
	// gtk_grid_attach(GTK_GRID(grid), button, 0, 0, 2, 1);
	// gtk_grid_attach(GTK_GRID(grid), rmLabel, 2, 0, 2, 1);
	// gtk_box_append(GTK_BOX(box), grid);
	// My_SetWindowChild(window, box);
	// My_PresentWindow(window);

	g_object_unref(builder);
}

int main(int argc, char **argv) {
	struct My_GAppOptions opts = {G_APPLICATION_FLAGS_NONE, argc, argv};
	struct My_GAppAndStatus appOut =
		CreateApp("com.test.hello", opts, activate);
	return appOut.status;
}
