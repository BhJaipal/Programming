#include "colors.h"
#include "macros.h"
#include "option.h"
#include <linux/keyboard.h>
#include <stdio.h>

int main() {
	for (int i = 0; i < 40; i++) {
		printf("%sHello\x1b[0m\t",
			   get_24_bit_color_escape_from_color(colors24Bit[i]));
		if (!((i + 1) % 8)) printf("\n");
	}

	DECL_ARRAY(SelectEl, TiOption);
	printf("%ld\n", sizeof(SelectEl));

	return 0;
}
