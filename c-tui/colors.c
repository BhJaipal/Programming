#include "colors.h"
#include <ctype.h>
#include <stdio.h>
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
		if (colors24Bit[i].colorFlag == flag)
			return colors24Bit[i].colorLabel;
	}
	return colors24Bit[23].colorLabel;
}

Color24BitFlag get_color_flag(char *colorName) {
	for (int i = 0; i < 24; i++) {
		if (!strcmp(colors24Bit[i].colorLabel, strlower(colorName)))
			return colors24Bit[i].colorFlag;
	}
	return colors24Bit[23].colorFlag;
}

char *get_24_bit_color_escape_from_color(Color24Bit color) {
	char *esc;
	sprintf(esc, "\x1b[%dm", color.colorFlag);
	return esc;
}

char *get_24_bit_color_escape_from_name(char *colorName) {
	char *esc;
	sprintf(esc, "\x1b[%dm", get_color_flag(colorName));
	return esc;
}

char *get_24_bit_color_escape_from_flag(Color24BitFlag flag) {
	char *esc;
	sprintf(esc, "\x1b[%dm", flag);
	return esc;
}

Color24Bit colors24Bit[40] = {
	{COLOR24_NONE, "none"},
	{COLOR24_BOLD, "bold"},
	{COLOR24_DARK, "dark"},
	{COLOR24_ITALIC, "italic"},
	{COLOR24_UNDERLINE, "underline"},
	{COLOR24_BLINK, "blink"},
	{COLOR24_UNKNOWN, "unknown"},
	{COLOR24_REVERSE_VIDEO, "reverse-video"},

	{COLOR24_BLACK, "black"},
	{COLOR24_RED, "red"},
	{COLOR24_GREEN, "green"},
	{COLOR24_YELLOW, "yellow"},
	{COLOR24_BLUE, "blue"},
	{COLOR24_MAGENTA, "magenta"},
	{COLOR24_TEAL, "teal"},
	{COLOR24_WHITE, "white"},
	{COLOR24_GREY, "grey"},
	{COLOR24_LIGHT_RED, "lightred"},
	{COLOR24_LIGHT_GREEN, "lightgreen"},
	{COLOR24_LIGHT_YELLOW, "lightyellow"},
	{COLOR24_LIGHT_BLUE, "lightblue"},
	{COLOR24_LIGHT_MAGENTA, "lightmagenta"},
	{COLOR24_LIGHT_TEAL, "lightteal"},
	{COLOR24_WHITE_2, "white"},

	{COLOR24_BLACK_BG, "black"},
	{COLOR24_RED_BG, "red"},
	{COLOR24_GREEN_BG, "green"},
	{COLOR24_YELLOW_BG, "yellow"},
	{COLOR24_BLUE_BG, "blue"},
	{COLOR24_MAGENTA_BG, "magenta"},
	{COLOR24_TEAL_BG, "teal"},
	{COLOR24_WHITE_BG, "white"},
	{COLOR24_GREY_BG, "grey"},
	{COLOR24_LIGHT_RED_BG, "lightred"},
	{COLOR24_LIGHT_GREEN_BG, "lightgreen"},
	{COLOR24_LIGHT_YELLOW_BG, "lightyellow"},
	{COLOR24_LIGHT_BLUE_BG, "lightblue"},
	{COLOR24_LIGHT_MAGENTA_BG, "lightmagenta"},
	{COLOR24_LIGHT_TEAL_BG, "lightteal"},
	{COLOR24_WHITE_2_BG, "white"},
};
