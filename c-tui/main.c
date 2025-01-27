#include "colors.h"
#include "select.h"

int main() {
	SelectOptions opts = ti_select_opt_list_new();
	TiOption file = ti_option_new("File", "file",
					ti_option_style_new(ti_default_colors[0], ti_default_colors[0]),
					ti_option_style_new(
						resetColor,
						ti_color_new(get_24_bit_color_from_flag(COLOR24_NONE), 165, 0))
	);

	TiOption edit = ti_option_new("Edit", "edit",
					ti_option_style_new(ti_default_colors[0], ti_default_colors[0]),
					ti_option_style_new(
						resetColor,
						ti_color_new(get_24_bit_color_from_flag(COLOR24_NONE), 165, 0))
	);
	opts.append(&opts, file);
	opts.append(&opts, edit);

	int i = 0;
	TiSelect sel = ti_select_new(1, "Options", opts, 30);
	ti_select_render(&sel, i);
	return 0;
}
