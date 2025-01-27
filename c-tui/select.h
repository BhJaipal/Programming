#ifndef TI_SELECT_H
#define TI_SELECT_H
#include "colors.h"
#include "option.h"
#include "macros.h"
#include <stdint.h>
#include <sys/types.h>

DECL_ARRAY(SelectOptions, TiOption, ti_select);

typedef struct {
	uint8_t label_show;
	char* label;
	SelectOptions opts;
	uint width;
} TiSelect;

typedef struct {
	Color24Bit label_bg_color;
} TiSelectStyle;

TiSelect ti_select_new(uint8_t label_show, char* label, SelectOptions opts, int width);

void ti_select_render(TiSelect *sel, uint8_t selectedIndex);

#endif //!TI_SELECT_H
