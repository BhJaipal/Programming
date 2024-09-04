#ifndef ALOO_INPUT_H
#define ALOO_INPUT_H
#include "types.h"

/******************** Private Funcs ********************/

alooWidget *__input_new();
const char *__input_get_val(alooWidget *input);
GtkEditable *__input_to_gtk(alooWidget *input);

/******************** Private Types ********************/

struct __alooInput {
	/// @brief Creates new Aloo Input
	alooWidget *(*new)();
	/// @brief Gets the value of the input
	const char *(*getValue)(alooWidget *input);
	/// @brief Converts Aloo Input to Gtk Input
	/// @param input input aloo Widget
	/// @return Gtk Editable
	GtkEditable *(*toGtk)(alooWidget *input);
};

extern struct __alooInput Input;

#endif // ALOO_INPUT_H
