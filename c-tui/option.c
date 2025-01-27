#include "option.h"
#include <stdlib.h>
#include <string.h>

TiOption ti_option_new(char *label, char *value, TiColor defaultColor, TiColor active) {
	TiOption opt;
	opt.label = malloc(sizeof(label));
	opt.value = malloc(sizeof(value));
	strcpy(opt.value, value);
	strcpy(opt.label, label);
	opt.defaultColor.is_24_256_reset_bit = defaultColor.is_24_256_reset_bit;
	opt.defaultColor.col256 = defaultColor.col256;
	opt.defaultColor.col24.colorFlag = defaultColor.col24.colorFlag;
	strcpy(opt.defaultColor.col24.colorLabel, defaultColor.col24.colorLabel);

	opt.activeColor.is_24_256_reset_bit = active.is_24_256_reset_bit;
	opt.activeColor.col256 = active.col256;
	opt.activeColor.col24.colorFlag = active.col24.colorFlag;
	strcpy(opt.activeColor.col24.colorLabel, active.col24.colorLabel);
	return opt;
}

void ti_option_free(TiOption *opt) {
	free(opt);
}

void ti_option_copy(TiOption *dest, TiOption src) {
	dest->activeColor = src.activeColor;
	dest->label = malloc(sizeof(src.label));
	strcpy(dest->label, src.label);
	dest->value = malloc(sizeof(src.value));
	strcpy(dest->value, src.value);
	dest->defaultColor = src.defaultColor;
}

