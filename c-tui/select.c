#include "select.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Declares
 * #__select_opt_list_pop,
 * #__select_opt_list_free,
 * #__select_opt_list_append
 */
TI_DECL_ARRAY_FUNCS(select_opt_list, SelectOptions, TiOption);

SelectOptions ti_select_opt_list_new() {
    SelectOptions arr;
    arr.arr = malloc(0);
    arr.len = 0;
	arr.pop = __select_opt_list_pop;
	arr.free = __select_opt_list_free;
	arr.append = __select_opt_list_append;
    return arr;
}

void __select_opt_list_free(SelectOptions *opts) {
	TI_ARRAY_FREE(opts);
}

void __select_opt_list_append(SelectOptions *options, TiOption opt) {
	TI_ARRAY_APPEND(options, opt);
}
TiOption __select_opt_list_pop(SelectOptions *options) {
	TiOption opt = options->arr[options->len - 1];
	options->arr = realloc(options->arr, sizeof(options->arr[0]) * (options->len - 1));
	return opt;
}

TiSelect ti_select_new(uint8_t label_show, char* label, SelectOptions opts, int width) {
	TiSelect sel = {label_show, label, opts, width};
	return sel;
}

uint8_t color_is_reset(TiColor color) {
	if (color.is_24_256_reset_bit != 1 || color.is_24_256_reset_bit != 0) return 1;
	else if (color.is_24_256_reset_bit == 0 && color.col256 == 0) return 1;
	else if (color.col24.colorFlag == 0 && color.is_24_256_reset_bit == 1) return 1;
	else return 0;
}

const char *fg_bg_combine(TiOptionStyle style) {
	// No background and foreground
	if (color_is_reset(style.background) && color_is_reset(style.foreground)) return "\x1b[0m";
	else if (color_is_reset(style.background)) {
		// only foreground
		return get_escape_from_ti_color(style.foreground);
	} else if (color_is_reset(style.foreground)) {
		// only background
		style.background.col24.colorFlag += 10;
		return get_escape_from_ti_color(style.background);

	// both bg and fg
	} else {
		char *esc;

		// both background and fg are either 24 bit or 256 bit
		if (style.background.is_24_256_reset_bit == style.foreground.is_24_256_reset_bit) {
			// both are 24-bit
			if (style.foreground.is_24_256_reset_bit == 1) {
				esc = malloc(sizeof(char[11]));
				sprintf(esc, "\x1b[%d;%dm", style.foreground.col24.colorFlag,
						style.background.col24.colorFlag + 10);
			} else {
				// both are 256-bit
				esc = malloc(sizeof(char[24]));
				sprintf(esc, "\x1b[48;5;%dm\x1b[38;5;%dm", style.background.col256, style.foreground.col256);
			}
		} else {
			esc = malloc(sizeof(char[18]));
			if (style.foreground.is_24_256_reset_bit == 0) {
				// fg is 256-bit, bg is 24-bit
				sprintf(esc, "\x1b[38;5;%dm\x1b[%dm", style.foreground.col256, style.background.col24.colorFlag + 10);
			} else {
				// bg is 256-bit, fg is 24-bit
				sprintf(esc, "\x1b[%dm\x1b[48;5;%dm", style.foreground.col24.colorFlag, style.background.col256);
			}
		}
		return esc;
	}
}

void ti_select_render(TiSelect *sel, uint8_t selectedIndex) {
	uint8_t w = 10;
	if (sel->width > 10) w = sel->width;
	if (sel->label_show) {
		if (strlen(sel->label) > w) {
			char labelOut[w - 2];
			for (int i = 0; i < w - 2; i++) { labelOut[i] = sel->label[i]; }
			printf("%s%s.%s.\x1b[0m\n", labelOut, "\x1b[90m", "\x1b[2m");
		} else {
			printf("%s\n", sel->label);
		}
	}
	for (uint8_t i = 0; i < sel->opts.len;i++) {
		TiOption opt = sel->opts.arr[i];
		if (strlen(opt.label) > w) {
			char labelOut[w - 2];
			for (uint8_t j = 0; j < w - 2; j++) { labelOut[j] = opt.label[j]; }
			printf("%d %d\n", i, selectedIndex);
			printf("%s%s\x1b[0m%s.\x1b[0m%s.\x1b[0m\n",
				fg_bg_combine((i == selectedIndex) ? opt.activeColor : opt.defaultColor),
				labelOut, "\x1b[90m", "\x1b[2m");
		} else {
			printf("%s%s\x1b[0m\n",
				fg_bg_combine((i == selectedIndex) ? opt.activeColor : opt.defaultColor),
				opt.label);
		}
	}
}
