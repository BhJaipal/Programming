#include "../include/box.h"
#include <gtk/gtk.h>

alooWidget *new_alooBox(GtkOrientation orientation, int spacing) {
	alooWidget *box = malloc(sizeof(alooWidget));
	box->type = ALOO_BOX;
	box->child = gtk_box_new(orientation, spacing);
	return box;
}
alooWidget *setBoxOrientation(alooWidget *box, GtkOrientation orientation) {
	if (!ALOO_IS_BOX(box)) {
		fprintf(stderr, "Invalid box");
		return box;
	}
	gtk_orientable_set_orientation(GTK_ORIENTABLE(ALOO_BOX_TO_GTK_BOX(box)),
								   orientation);
	return box;
}
GtkOrientation getBoxOrientation(alooWidget *box) {
	if (!ALOO_IS_BOX(box)) {
		fprintf(stderr, "Invalid box");
		return GTK_ORIENTATION_HORIZONTAL;
	}
	return gtk_orientable_get_orientation(
		GTK_ORIENTABLE(ALOO_BOX_TO_GTK_BOX(box)));
}

alooWidget *boxAppend(alooWidget *box, GtkWidget *widget) {
	if (!ALOO_IS_BOX(box)) {
		fprintf(stderr, "Invalid box");
		return box;
	}
	gtk_box_append(ALOO_BOX_TO_GTK_BOX(box), widget);
	return box;
}
alooWidget *boxPrepend(alooWidget *box, GtkWidget *widget) {
	if (!ALOO_IS_BOX(box)) {
		fprintf(stderr, "Invalid box");
		return box;
	}
	gtk_box_prepend(ALOO_BOX_TO_GTK_BOX(box), widget);
	return box;
}
alooWidget *boxRemove(alooWidget *box, GtkWidget *widget) {
	if (!ALOO_IS_BOX(box)) {
		fprintf(stderr, "Invalid box");
		return box;
	}
	gtk_box_remove(ALOO_BOX_TO_GTK_BOX(box), widget);
	return box;
}

alooWidget *setBoxSpacing(alooWidget *box, int spacing) {
	if (!ALOO_IS_BOX(box)) {
		fprintf(stderr, "Invalid box");
		return box;
	}
	gtk_box_set_spacing(ALOO_BOX_TO_GTK_BOX(box), spacing);
	return box;
}
int getBoxSpacing(alooWidget *box) {
	if (!ALOO_IS_BOX(box)) {
		fprintf(stderr, "Invalid box");
		return 0;
	}
	return gtk_box_get_spacing(ALOO_BOX_TO_GTK_BOX(box));
}
gboolean getBoxHomogeneous(alooWidget *box) {
	if (!ALOO_IS_BOX(box)) {
		fprintf(stderr, "Invalid box");
		return 0;
	}
	return gtk_box_get_homogeneous(ALOO_BOX_TO_GTK_BOX(box));
}
alooWidget *setBoxHomogeneous(alooWidget *box, gboolean homogeneous) {
	if (!ALOO_IS_BOX(box)) {
		fprintf(stderr, "Invalid box");
		return box;
	}
	gtk_box_set_homogeneous(ALOO_BOX_TO_GTK_BOX(box), homogeneous);
	return box;
}

GtkBaselinePosition getBoxBaselinePosition(alooWidget *box) {
	if (!ALOO_IS_BOX(box)) {
		fprintf(stderr, "Invalid box");
		return GTK_BASELINE_POSITION_TOP;
	}
	return gtk_box_get_baseline_position(ALOO_BOX_TO_GTK_BOX(box));
}
alooWidget *setBoxBaselinePosition(alooWidget *box,
								   GtkBaselinePosition position) {
	if (!ALOO_IS_BOX(box)) {
		fprintf(stderr, "Invalid box");
		return box;
	}
	gtk_box_set_baseline_position(ALOO_BOX_TO_GTK_BOX(box), position);
	return box;
}

alooWidget *boxInsertChildAfter(alooWidget *box, alooWidget *child,
								alooWidget *after) {
	if (!ALOO_IS_BOX(box)) {
		fprintf(stderr, "Invalid box");
		return box;
	}
	gtk_box_insert_child_after(ALOO_BOX_TO_GTK_BOX(box),
							   ALOO_WIDGET_TO_GTK(child),
							   ALOO_WIDGET_TO_GTK(after));
	return box;
}