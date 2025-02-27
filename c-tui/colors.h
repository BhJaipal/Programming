#include <stdint.h>
#ifndef TI_COLOR_H
#define TI_COLOR_H 1

typedef enum {
	COLOR24_NONE = 0,
	COLOR24_BOLD = 1,
	COLOR24_DARK = 2,
	COLOR24_ITALIC = 3,
	COLOR24_UNDERLINE = 4,
	COLOR24_BLINK = 5,
	/* I never used remaining 2 */
	COLOR24_UNKNOWN = 6,
	COLOR24_REVERSE_VIDEO = 7,

	/* Colors */
	COLOR24_BLACK = 30,
	COLOR24_RED = 31,
	COLOR24_GREEN = 32,
	COLOR24_YELLOW = 33,
	COLOR24_BLUE = 34,
	COLOR24_MAGENTA = 35,
	COLOR24_TEAL = 36,
	COLOR24_WHITE = 37,
	COLOR24_GREY = 90,
	COLOR24_LIGHT_RED = 91,
	COLOR24_LIGHT_GREEN = 92,
	COLOR24_LIGHT_YELLOW = 93,
	COLOR24_LIGHT_BLUE = 94,
	COLOR24_LIGHT_MAGENTA = 95,
	COLOR24_LIGHT_TEAL = 96,
	COLOR24_WHITE_2 = 97,
} Color24BitFlag;

typedef struct {
	Color24BitFlag colorFlag;
	char colorLabel[20];
} Color24Bit;

typedef struct {
	Color24Bit col24;
	uint8_t col256;
	/**
	 * If 24 bit, 1
	 * If 256 bit, 0
	 * else reset, -1
	 */
	uint8_t is_24_256_reset_bit;
} TiColor;

extern TiColor resetColor;
extern Color24Bit reset24Bit;

extern TiColor ti_default_colors[24];

Color24Bit get_24_bit_color_from_flag(Color24BitFlag flag);
TiColor ti_color_new(Color24Bit color24, uint8_t color256, uint8_t is_24_256_reset_bit);

const char *get_escape_from_ti_color(TiColor ti_color);

const char *get_256_bit_color_escape(uint8_t colorCode);

const char *get_color_name(Color24BitFlag flag);
Color24BitFlag get_color_flag(char *colorName);


char *get_24_bit_color_escape_from_color(Color24Bit color);
char *get_24_bit_color_escape_from_name(char *colorName);
char *get_24_bit_color_escape(Color24BitFlag flag);

#endif // !TI_COLOR_H
