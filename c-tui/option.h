#include "colors.h"
#ifndef TI_OPTION_H
#define TI_OPTION_H 1

typedef struct {
	char *label;
	char *value;
	TiColor defaultColor;
	TiColor activeColor;
} TiOption;

TiOption ti_option_new(char *label, char *value, TiColor defaultColor, TiColor activeColor);

void ti_option_copy(TiOption *dest, TiOption src);

#endif // !TI_OPTION_H
