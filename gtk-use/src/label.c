#include "label.h"
#include "utils/error.h"
#include "widget.h"

alooWidget *__newLabel(const char *val) {
	return Widget.new(ALOO_LABEL, gtk_label_new(val));
}
GtkLabel *__LabeltoGtk(alooWidget *wid) {
	if (!Widget.check.isLabel(wid)) {
		throw_error("Invalid label");
		return GTK_LABEL(Label.new("Invalid label")->child);
	}
	return GTK_LABEL(wid->child);
}

struct __alooLabel Label = {__newLabel, __LabeltoGtk};