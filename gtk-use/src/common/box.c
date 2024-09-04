#include "common/box.h"
#include "common/widget.h"
#include "utils/error.h"
#include <gtk/gtk.h>

alooWidget *__new_alooBox(GtkOrientation orientation, int spacing) {
	alooWidget *box = malloc(sizeof(alooWidget));
	box->type = ALOO_BOX;
	box->child = gtk_box_new(orientation, spacing);
	return box;
}
alooWidget *__setBoxOrientation(alooWidget *box, GtkOrientation orientation) {
	if (!Widget.check.isBox(box)) {
		throw_error("Invalid box");
		return box;
	}
	gtk_orientable_set_orientation(GTK_ORIENTABLE(Box.toGtk(box)), orientation);
	return box;
}
GtkOrientation __getBoxOrientation(alooWidget *box) {
	if (!Widget.check.isBox(box)) {
		throw_error("Invalid box");
		return GTK_ORIENTATION_HORIZONTAL;
	}
	return gtk_orientable_get_orientation(GTK_ORIENTABLE(Box.toGtk(box)));
}

alooWidget *__boxAppendGtk(alooWidget *box, GtkWidget *widget) {
	if (!Widget.check.isBox(box)) {
		throw_error("Invalid box");
		return box;
	}
	gtk_box_append(Box.toGtk(box), widget);
	return box;
}
alooWidget *__boxPrependGtk(alooWidget *box, GtkWidget *widget) {
	if (!Widget.check.isBox(box)) {
		throw_error("Invalid box");
		return box;
	}
	gtk_box_prepend(Box.toGtk(box), widget);
	return box;
}
alooWidget *__boxRemoveGtk(alooWidget *box, GtkWidget *widget) {
	if (!Widget.check.isBox(box)) {
		throw_error("Invalid box");
		return box;
	}
	gtk_box_remove(Box.toGtk(box), widget);
	return box;
}

alooWidget *__boxAppend(alooWidget *box, alooWidget *widget) {
	if (!Widget.check.isBox(box)) {
		throw_error("Invalid box");
		return box;
	}
	gtk_box_append(Box.toGtk(box), Widget.to_gtk(widget));
	return box;
}
alooWidget *__boxPrepend(alooWidget *box, alooWidget *widget) {
	if (!Widget.check.isBox(box)) {
		throw_error("Invalid box");
		return box;
	}
	gtk_box_prepend(Box.toGtk(box), Widget.to_gtk(widget));
	return box;
}
alooWidget *__boxRemove(alooWidget *box, alooWidget *widget) {
	if (!Widget.check.isBox(box)) {
		throw_error("Invalid box");
		return box;
	}
	gtk_box_remove(Box.toGtk(box), Widget.to_gtk(widget));
	return box;
}

alooWidget *__setBoxSpacing(alooWidget *box, int spacing) {
	if (!Widget.check.isBox(box)) {
		throw_error("Invalid box");
		return box;
	}
	gtk_box_set_spacing(Box.toGtk(box), spacing);
	return box;
}
int __getBoxSpacing(alooWidget *box) {
	if (!Widget.check.isBox(box)) {
		throw_error("Invalid box");
		return 0;
	}
	return gtk_box_get_spacing(Box.toGtk(box));
}
gboolean __getBoxHomogeneous(alooWidget *box) {
	if (!Widget.check.isBox(box)) {
		throw_error("Invalid box");
		return 0;
	}
	return gtk_box_get_homogeneous(Box.toGtk(box));
}
alooWidget *__setBoxHomogeneous(alooWidget *box, gboolean homogeneous) {
	if (!Widget.check.isBox(box)) {
		throw_error("Invalid box");
		return box;
	}
	gtk_box_set_homogeneous(Box.toGtk(box), homogeneous);
	return box;
}

GtkBaselinePosition __getBoxBaselinePosition(alooWidget *box) {
	if (!Widget.check.isBox(box)) {
		throw_error("Invalid box");
		return GTK_BASELINE_POSITION_TOP;
	}
	return gtk_box_get_baseline_position(Box.toGtk(box));
}
alooWidget *__setBoxBaselinePosition(alooWidget *box,
									 GtkBaselinePosition position) {
	if (!Widget.check.isBox(box)) {
		throw_error("Invalid box");
		return box;
	}
	gtk_box_set_baseline_position(Box.toGtk(box), position);
	return box;
}

alooWidget *__boxInsertChildAfter(alooWidget *box, alooWidget *child,
								  alooWidget *after) {
	if (!Widget.check.isBox(box)) {
		throw_error("Invalid box");
		return box;
	}
	gtk_box_insert_child_after(Box.toGtk(box), child->child, after->child);
	return box;
}
GtkBox *__toGtk(alooWidget *widget) {
	if (Widget.check.isBox(widget)) return GTK_BOX(widget->child);
	throw_error("Invalid box");
	return GTK_BOX(Box.new(GTK_ORIENTATION_HORIZONTAL, 0)->child);
}

struct _alooBox Box = {
	__new_alooBox,
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
	__setBoxBaselinePosition,
	__toGtk,
};