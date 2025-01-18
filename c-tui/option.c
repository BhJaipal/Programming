#include "option.h"
#include <stdlib.h>
#include <string.h>

TiOption* ti_option_new(char *label, char *value) {
	TiOption* opt = malloc(sizeof(label) + sizeof(value));
	strcpy(opt->value, value);
	strcpy(opt->label, label);
	return opt;
}

void ti_option_free(TiOption *opt) {
	free(opt);
}
