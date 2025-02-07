#include "colors.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *strlower(char *str) {
	int i = 0;
	while (str[i] != 0) {
		if (str[i] >= 65 && str[i] <= 90) {
			str[i] = tolower(str[i]);
		}
	}
	return str;
}

const char *get_color_name(Color24BitFlag flag) {
	for (int i = 0; i < 24; i++) {
		if (ti_default_colors[i].col24.colorFlag == flag)
			return ti_default_colors[i].col24.colorLabel;
	}
	return ti_default_colors[23].col24.colorLabel;
}

Color24BitFlag get_color_flag(char *colorName) {
	for (int i = 0; i < 24; i++) {
		if (!strcmp(ti_default_colors[i].col24.colorLabel, strlower(colorName)))
			return ti_default_colors[i].col24.colorFlag;
	}
	return ti_default_colors[23].col24.colorFlag;
}

char *get_24_bit_color_escape_from_color(Color24Bit color) {
	char *esc = malloc(sizeof(char) * 9);
	sprintf(esc, "\x1b[%dm", color.colorFlag);
	return esc;
}

char *get_24_bit_color_escape_from_name(char *colorName) {
	char *esc = malloc(sizeof(char) * 9);
	sprintf(esc, "\x1b[%dm", get_color_flag(colorName));
	return esc;
}

char *get_24_bit_color_escape_from_flag(Color24BitFlag flag) {
	char *esc = malloc(sizeof(char) * 9);;
	sprintf(esc, "\x1b[%dm", flag);
	return esc;
}

const char *get_256_bit_color_escape(uint8_t colorCode) {
	char *out = malloc(sizeof(char) * 9);
	sprintf(out, "\x1b[48;5;%dm", colorCode);
	return out;
}

const char *get_escape_from_ti_color(TiColor ti_color) {
	switch (ti_color.is_24_256_reset_bit) {
		case 1:
			return get_24_bit_color_escape_from_color(ti_color.col24);
		case 0:
			return get_256_bit_color_escape(ti_color.col256);
		default:
			return "\x1b[0m";
	}
	return "\x1b[0m";
}

TiColor ti_color_new(Color24Bit color24, uint8_t color256, uint8_t is_24_256_reset_bit) {
	TiColor col = {color24, color256, is_24_256_reset_bit};
	return col;
}

Color24Bit get_24_bit_color_from_flag(Color24BitFlag flag) {
	for (int i = 0; i < 24; i++) {
		if (flag == ti_default_colors[i].col24.colorFlag)
			return ti_default_colors[i].col24;
	}
	return ti_default_colors[0].col24;
}

TiColor resetColor = {{COLOR24_NONE, "none"}, 0, 1};
Color24Bit reset24Bit = {COLOR24_NONE, "none"};


TiColor ti_default_colors[] = {
	{{COLOR24_NONE, "none"}, 0, 1},
	{{COLOR24_BOLD, "bold"}, 0, 1},
	{{COLOR24_DARK, "dark"}, 0, 1},
	{{COLOR24_ITALIC, "italic"}, 0, 1},
	{{COLOR24_UNDERLINE, "underline"}, 0, 1},
	{{COLOR24_BLINK, "blink"}, 0, 1},
	{{COLOR24_UNKNOWN, "unknown"}, 0, 1},
	{{COLOR24_REVERSE_VIDEO, "reverse-video"}, 0, 1},

	{{COLOR24_BLACK, "black"}, 0, 1},
	{{COLOR24_RED, "red"}, 0, 1},
	{{COLOR24_GREEN, "green"}, 0, 1},
	{{COLOR24_YELLOW, "yellow"}, 0, 1},
	{{COLOR24_BLUE, "blue"}, 0, 1},
	{{COLOR24_MAGENTA, "magenta"}, 0, 1},
	{{COLOR24_TEAL, "teal"}, 0, 1},
	{{COLOR24_WHITE, "white"}, 0, 1},
	{{COLOR24_GREY, "grey"}, 0, 1},
	{{COLOR24_LIGHT_RED, "lightred"}, 0, 1},
	{{COLOR24_LIGHT_GREEN, "lightgreen"}, 0, 1},
	{{COLOR24_LIGHT_YELLOW, "lightyellow"}, 0, 1},
	{{COLOR24_LIGHT_BLUE, "lightblue"}, 0, 1},
	{{COLOR24_LIGHT_MAGENTA, "lightmagenta"}, 0, 1},
	{{COLOR24_LIGHT_TEAL, "lightteal"}, 0, 1},
	{{COLOR24_WHITE_2, "white"}, 0, 1},
};
