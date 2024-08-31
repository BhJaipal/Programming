#include "box.h"
#include "macros.h"
#include <gtk/gtk.h>

GtkWidget *ALOO_BOX_WIDGET(alooWidget *x) { return x->child; }

gboolean ALOO_IS_BOX(alooWidget *x) {
	return x->type == ALOO_BOX || ALOO_NEW_WIDGET && GTK_IS_BOX(x->child);
}

alooWidget *__new_alooBox(GtkOrientation orientation, int spacing) {
	alooWidget *box = malloc(sizeof(alooWidget));
	box->type = ALOO_BOX;
	box->child = gtk_box_new(orientation, spacing);
	return box;
}
alooWidget *__setBoxOrientation(alooWidget *box, GtkOrientation orientation) {
	if (!ALOO_IS_BOX(box)) {
		fprintf(stderr, "Invalid box");
		return box;
	}
	gtk_orientable_set_orientation(GTK_ORIENTABLE(ALOO_BOX_TO_GTK_BOX(box)),
								   orientation);
	return box;
}
GtkOrientation __getBoxOrientation(alooWidget *box) {
	if (!ALOO_IS_BOX(box)) {
		fprintf(stderr, "Invalid box");
		return GTK_ORIENTATION_HORIZONTAL;
	}
	return gtk_orientable_get_orientation(
		GTK_ORIENTABLE(ALOO_BOX_TO_GTK_BOX(box)));
}

alooWidget *__boxAppendGtk(alooWidget *box, GtkWidget *widget) {
	if (!ALOO_IS_BOX(box)) {
		fprintf(stderr, "Invalid box");
		return box;
	}
	gtk_box_append(ALOO_BOX_TO_GTK_BOX(box), widget);
	return box;
}
alooWidget *__boxPrependGtk(alooWidget *box, GtkWidget *widget) {
	if (!ALOO_IS_BOX(box)) {
		fprintf(stderr, "Invalid box");
		return box;
	}
	gtk_box_prepend(ALOO_BOX_TO_GTK_BOX(box), widget);
	return box;
}
alooWidget *__boxRemoveGtk(alooWidget *box, GtkWidget *widget) {
	if (!ALOO_IS_BOX(box)) {
		fprintf(stderr, "Invalid box");
		return box;
	}
	gtk_box_remove(ALOO_BOX_TO_GTK_BOX(box), widget);
	return box;
}

alooWidget *__boxAppend(alooWidget *box, alooWidget *widget) {
	if (!ALOO_IS_BOX(box)) {
		fprintf(stderr, "Invalid box");
		return box;
	}
	gtk_box_append(ALOO_BOX_TO_GTK_BOX(box), ALOO_WIDGET_TO_GTK(widget));
	return box;
}
alooWidget *__boxPrepend(alooWidget *box, alooWidget *widget) {
	if (!ALOO_IS_BOX(box)) {
		fprintf(stderr, "Invalid box");
		return box;
	}
	gtk_box_prepend(ALOO_BOX_TO_GTK_BOX(box), ALOO_WIDGET_TO_GTK(widget));
	return box;
}
alooWidget *__boxRemove(alooWidget *box, alooWidget *widget) {
	if (!ALOO_IS_BOX(box)) {
		fprintf(stderr, "Invalid box");
		return box;
	}
	gtk_box_remove(ALOO_BOX_TO_GTK_BOX(box), ALOO_WIDGET_TO_GTK(widget));
	return box;
}

alooWidget *__setBoxSpacing(alooWidget *box, int spacing) {
	if (!ALOO_IS_BOX(box)) {
		fprintf(stderr, "Invalid box");
		return box;
	}
	gtk_box_set_spacing(ALOO_BOX_TO_GTK_BOX(box), spacing);
	return box;
}
int __getBoxSpacing(alooWidget *box) {
	if (!ALOO_IS_BOX(box)) {
		fprintf(stderr, "Invalid box");
		return 0;
	}
	return gtk_box_get_spacing(ALOO_BOX_TO_GTK_BOX(box));
}
gboolean __getBoxHomogeneous(alooWidget *box) {
	if (!ALOO_IS_BOX(box)) {
		fprintf(stderr, "Invalid box");
		return 0;
	}
	return gtk_box_get_homogeneous(ALOO_BOX_TO_GTK_BOX(box));
}
alooWidget *__setBoxHomogeneous(alooWidget *box, gboolean homogeneous) {
	if (!ALOO_IS_BOX(box)) {
		fprintf(stderr, "Invalid box");
		return box;
	}
	gtk_box_set_homogeneous(ALOO_BOX_TO_GTK_BOX(box), homogeneous);
	return box;
}

GtkBaselinePosition __getBoxBaselinePosition(alooWidget *box) {
	if (!ALOO_IS_BOX(box)) {
		fprintf(stderr, "Invalid box");
		return GTK_BASELINE_POSITION_TOP;
	}
	return gtk_box_get_baseline_position(ALOO_BOX_TO_GTK_BOX(box));
}
alooWidget *__setBoxBaselinePosition(alooWidget *box,
									 GtkBaselinePosition position) {
	if (!ALOO_IS_BOX(box)) {
		fprintf(stderr, "Invalid box");
		return box;
	}
	gtk_box_set_baseline_position(ALOO_BOX_TO_GTK_BOX(box), position);
	return box;
}

alooWidget *__boxInsertChildAfter(alooWidget *box, alooWidget *child,
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

struct _alooBox Box = {__new_alooBox,
					   __setBoxOrientation,
					   __getBoxOrientation,
					   __boxAppendGtk,
					   __boxPrependGtk,
					   __boxRemoveGtk,
					   __boxAppend,
					   __boxPrepend,
					   __boxRemove,
					   __boxInsertChildAfter,
					   __setBoxSpacing,
					   __getBoxSpacing,
					   __getBoxHomogeneous,
					   __setBoxHomogeneous,
					   __getBoxBaselinePosition,
					   __setBoxBaselinePosition};