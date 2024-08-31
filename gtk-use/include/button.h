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

/******************** Private Types ********************/

typedef alooWidget *(*__newButton_Type)();
typedef alooWidget *(*__newButtonWithLabel_Type)(const char *label);
typedef alooWidget *(*__setLabel_Type)(alooWidget *btn, char const *name);
typedef alooWidget *(*__setChild_Type)(alooWidget *btn, alooWidget *child);
typedef alooWidget *(*__setIcon_Type)(alooWidget *btn, const char *child);
typedef alooWidget *(*__setUseUnderline_Type)(alooWidget *btn, gboolean yes);

/******************** Public ********************/

struct _alooButton {
	/// @brief Creates new Aloo Button without label
	__newButton_Type new;
	/// @brief Creates new Aloo Button with label
	__newButtonWithLabel_Type newWithLabel;
	/// @brief Sets the label of the button
	__setLabel_Type label;
	/// @brief Sets the child of the button
	__setChild_Type child;
	/// @brief Sets the icon of the button
	__setIcon_Type icon;
	/// @brief Sets whether to use underline or not in the button
	__setUseUnderline_Type useUnderline;
};

extern struct _alooButton Button;

#endif // ALOO_BUTTON_H