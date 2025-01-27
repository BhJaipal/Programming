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
			for (uint8_t i = 0; i < w - 2; i++) { labelOut[i] = opt.label[i]; }
			printf("%s%s\x1b[0m%s.%s.\x1b[0m\n",
				get_escape_from_from_ti_color(i == selectedIndex ? opt.activeColor : opt.defaultColor),
				labelOut, "\x1b[90m", "\x1b[2m");
		} else {
			printf("%s%s\x1b[0m\n",
				get_escape_from_from_ti_color(i == selectedIndex ? opt.activeColor : opt.defaultColor),
				opt.label);
		}
	}
}
