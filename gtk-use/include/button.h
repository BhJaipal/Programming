/**
 * @file button.h
 * @author Jaipal001
 * @brief Aloo Button related functions
 */
#ifndef ALOO_BUTTON_H
#define ALOO_BUTTON_H
#include "types.h"

/******************** Private Funcs ********************/

alooWidget *__newButton();
alooWidget *__newButtonWithLabel(const char *label);
alooWidget *__setLabel(alooWidget *btn, char const *name);
alooWidget *__setChild(alooWidget *btn, alooWidget *child);
alooWidget *__setIcon(alooWidget *btn, const char *child);
alooWidget *__setUseUnderline(alooWidget *btn, gboolean yes);
GtkButton *__toButtonGtk(alooWidget *wid);

/******************** Private Types ********************/

struct _alooButton {
	/// @brief Creates new Aloo Button without label
	alooWidget *(*new)();
	/// @brief Creates new Aloo Button with label
	alooWidget *(*newWithLabel)(const char *label);
	/// @brief Sets the label of the button
	alooWidget *(*label)(alooWidget *btn, char const *name);
	/// @brief Sets the child of the button
	alooWidget *(*child)(alooWidget *btn, alooWidget *child);
	/// @brief Sets the icon of the button
	alooWidget *(*icon)(alooWidget *btn, const char *child);
	/// @brief Sets whether to use underline or not in the button
	alooWidget *(*useUnderline)(alooWidget *btn, gboolean yes);
	/// @brief Converts Aloo Button to Gtk Button
	GtkButton *(*toGtk)(alooWidget *wid);
};

/******************** Public ********************/

extern struct _alooButton Button;

#endif // ALOO_BUTTON_H