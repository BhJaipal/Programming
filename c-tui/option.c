#include "option.h"
#include <stdlib.h>
#include <string.h>

TiOption ti_option_new(char *label, char *value, TiOptionStyle defaultColor, TiOptionStyle active) {
	TiOption opt;
	opt.label = malloc(sizeof(label));
	opt.value = malloc(sizeof(value));
	strcpy(opt.value, value);
	strcpy(opt.label, label);

	opt.defaultColor.background.is_24_256_reset_bit = defaultColor.background.is_24_256_reset_bit;
	opt.defaultColor.background.col256 = defaultColor.background.col256;
	opt.defaultColor.background.col24.colorFlag = defaultColor.background.col24.colorFlag;
	strcpy(opt.defaultColor.background.col24.colorLabel, defaultColor.background.col24.colorLabel);

	opt.defaultColor.foreground.is_24_256_reset_bit = defaultColor.foreground.is_24_256_reset_bit;
	opt.defaultColor.foreground.col256 = defaultColor.foreground.col256;
	opt.defaultColor.foreground.col24.colorFlag = defaultColor.foreground.col24.colorFlag;
	strcpy(opt.defaultColor.foreground.col24.colorLabel, defaultColor.foreground.col24.colorLabel);

	opt.activeColor.background.is_24_256_reset_bit = active.background.is_24_256_reset_bit;
	opt.activeColor.background.col256 = active.background.col256;
	opt.activeColor.background.col24.colorFlag = active.background.col24.colorFlag;
	strcpy(opt.activeColor.background.col24.colorLabel, active.background.col24.colorLabel);

	opt.activeColor.foreground.is_24_256_reset_bit = active.foreground.is_24_256_reset_bit;
	opt.activeColor.foreground.col256 = active.foreground.col256;
	opt.activeColor.foreground.col24.colorFlag = active.foreground.col24.colorFlag;
	strcpy(opt.activeColor.background.col24.colorLabel, active.foreground.col24.colorLabel);
	return opt;
}

void ti_option_free(TiOption *opt) {
	free(opt->label);
	free(opt->value);
	free(opt);
}

TiOptionStyle ti_option_style_new(TiColor fg, TiColor bg) {
	TiOptionStyle style = {fg, bg};
	return style;
}

void ti_option_copy(TiOption *dest, TiOption src) {
	dest->activeColor = src.activeColor;
	dest->label = malloc(sizeof(src.label));
	strcpy(dest->label, src.label);
	dest->value = malloc(sizeof(src.value));
	strcpy(dest->value, src.value);
	dest->defaultColor = src.defaultColor;
}

