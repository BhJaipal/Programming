#include "colors.h"
#ifndef TI_OPTION_H
#define TI_OPTION_H 1

typedef struct {
	TiColor foreground;
	TiColor background;
} TiOptionStyle;

typedef struct {
	char *label;
	char *value;
	TiOptionStyle defaultColor;
	TiOptionStyle activeColor;
} TiOption;

TiOption ti_option_new(char *label, char *value, TiOptionStyle defaultColor, TiOptionStyle activeColor);

void ti_option_copy(TiOption *dest, TiOption src);

TiOptionStyle ti_option_style_new(TiColor fg, TiColor bg);

#endif // !TI_OPTION_H
