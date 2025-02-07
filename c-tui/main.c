#include "colors.h"
#include "select.h"
#include <stdio.h>

int main() {
	SelectOptions opts = ti_select_opt_list_new();
	TiOption file = ti_option_new("File", "file",
					ti_option_style_new(resetColor, resetColor),
					ti_option_style_new(resetColor, ti_color_new(reset24Bit, 165, 0))
	);

	TiOption edit = ti_option_new("Edit", "edit",
					ti_option_style_new(resetColor, resetColor),
					ti_option_style_new(resetColor, ti_color_new(reset24Bit, 165, 0))
	);
	opts.append(&opts, file);
	opts.append(&opts, edit);

	int i = 0;
	TiSelect sel = ti_select_new(1, "Options", opts, 30);
	ti_select_render(&sel, i);
	printf("Select size: %lu\ndefault Colors: %lu\n", sizeof(sel), sizeof(ti_default_colors));
	printf("Reset Color: %lu\nReset 24-bit: %lu\n", sizeof(resetColor), sizeof(reset24Bit));
	return 0;
}
