#include "../include/label.h"
#include "../include/widget.h"

alooWidget *newLabel(const char *val) {
	return NewWidget(ALOO_LABEL, gtk_label_new(val));
}
