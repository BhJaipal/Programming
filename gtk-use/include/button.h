#ifndef ALOO_BUTTON_H
#define ALOO_BUTTON_H
#include "types.h"

#define ALOO_BTN_TO_GTK(x) GTK_BUTTON(x->child)

alooWidget *newButton();
alooWidget *newButtonWithLabel(const char *label);

#endif // ALOO_BUTTON_H