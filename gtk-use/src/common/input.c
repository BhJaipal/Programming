#include "common/input.h"
#include "common/widget.h"
#include "utils/error.h"

alooWidget *__input_new(char *label) {
	return Widget.new(ALOO_INPUT, gtk_editable_label_new(label));
}
const char *__input_get_val(alooWidget *input) {
	return gtk_editable_get_text(Input.toGtk(input));
}

GtkEditable *__input_to_gtk(alooWidget *input) {
	if (!Widget.check.isInput(input)) {
		throw_error("Invalid input");
		return GTK_EDITABLE(Input.new("Invalid")->child);
	}
	return GTK_EDITABLE(input->child);
}

struct __alooInput Input = {
	__input_new,
	__input_get_val,
	__input_to_gtk,
};
