#ifndef TI_OPTION_H
#define TI_OPTION_H 1

typedef struct {
	char *label;
	char *value;
} TiOption;

TiOption* ti_option_new(char *label, char *value);

#endif // !TI_OPTION_H
