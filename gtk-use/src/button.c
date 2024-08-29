#include "../include/button.h"
#include "../include/widget.h"

alooWidget *newButton() {
	alooWidget *btn = NewWidget(ALOO_BUTTON, gtk_button_new());
	return btn;
}
alooWidget *newButtonWithLabel(const char *label) {
	alooWidget *btn = NewWidget(ALOO_BUTTON, gtk_button_new());
	gtk_button_set_label(ALOO_BTN_TO_GTK(btn), label);
	return btn;
}
