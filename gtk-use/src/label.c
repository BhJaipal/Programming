#include "label.h"
#include "widget.h"

alooWidget *__newLabel(const char *val) {
	return Widget.new(ALOO_LABEL, gtk_label_new(val));
}

struct __alooLabel Label = {__newLabel};