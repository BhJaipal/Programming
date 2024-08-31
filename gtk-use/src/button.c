#include "button.h"
#include "macros.h"
#include "widget.h"

alooWidget *__newButton() {
	alooWidget *btn = Widget.new(ALOO_BUTTON, gtk_button_new());
	return btn;
}
alooWidget *__newButtonWithLabel(const char *label) {
	alooWidget *btn = Widget.new(ALOO_BUTTON, gtk_button_new());
	gtk_button_set_label(ALOO_BTN_TO_GTK(btn), label);
	return btn;
}
alooWidget *__setLabel(alooWidget *btn, char const *name) {
	gtk_button_set_label(ALOO_BTN_TO_GTK(btn), name);
	return btn;
}
alooWidget *__setChild(alooWidget *btn, alooWidget *child) {
	gtk_button_set_child(ALOO_BTN_TO_GTK(btn), ALOO_WIDGET_TO_GTK(child));
	return btn;
}
alooWidget *__setIcon(alooWidget *btn, const char *icon) {
	gtk_button_set_icon_name(ALOO_BTN_TO_GTK(btn), icon);
	return btn;
}
alooWidget *__setUseUnderline(alooWidget *btn, gboolean yes) {
	gtk_button_set_use_underline(ALOO_BTN_TO_GTK(btn), yes);
	return btn;
}

struct _alooButton Button = {__newButton, __newButtonWithLabel,
							 __setLabel,  __setChild,
							 __setIcon,	  __setUseUnderline};
