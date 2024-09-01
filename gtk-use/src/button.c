#include "button.h"
#include "utils/error.h"
#include "widget.h"

alooWidget *__newButton() {
	alooWidget *btn = Widget.new(ALOO_BUTTON, gtk_button_new());
	return btn;
}
alooWidget *__newButtonWithLabel(const char *label) {
	alooWidget *btn = Widget.new(ALOO_BUTTON, gtk_button_new());
	gtk_button_set_label(Button.toGtk(btn), label);
	return btn;
}
alooWidget *__setLabel(alooWidget *btn, char const *name) {
	gtk_button_set_label(Button.toGtk(btn), name);
	return btn;
}
alooWidget *__setChild(alooWidget *btn, alooWidget *child) {
	gtk_button_set_child(Button.toGtk(btn), Widget.to_gtk(child));
	return btn;
}
alooWidget *__setIcon(alooWidget *btn, const char *icon) {
	gtk_button_set_icon_name(Button.toGtk(btn), icon);
	return btn;
}
alooWidget *__setUseUnderline(alooWidget *btn, gboolean yes) {
	gtk_button_set_use_underline(Button.toGtk(btn), yes);
	return btn;
}

GtkButton *__toButtonGtk(alooWidget *wid) {
	if (Widget.check.isButton(wid)) return GTK_BUTTON(wid->child);
	throw_error("Invalid button");
	return GTK_BUTTON(Button.new()->child);
}

struct _alooButton Button = {
	__newButton, __newButtonWithLabel, __setLabel,	  __setChild,
	__setIcon,	 __setUseUnderline,	   __toButtonGtk,
};
