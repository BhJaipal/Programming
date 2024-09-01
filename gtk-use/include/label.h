/**
 * @file label.h
 * @author Jaipal001
 * @brief Aloo Label related functions
 */
#ifndef ALOO_LABEL_H
#define ALOO_LABEL_H
#include "types.h"

/******************** Private Funcs ********************/

alooWidget *__newLabel(const char *val);

/******************** Private Types ********************/

typedef alooWidget *(*_newLabelType)(const char *val);

struct __alooLabel {
	_newLabelType new;
};

/******************** Public ********************/

extern struct __alooLabel Label;

#endif // ALOO_LABEL_H