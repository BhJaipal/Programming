#include "repl.h"
#include <stdio.h>
#include <string.h>

char REPL_outArr[30720];
__U32_TYPE REPL_pointer_pos = 0;
__U32_TYPE REPL_loop_start_pos = 0;
__U32_TYPE REPL_loop_end_pos = 0;
int REPL_printing = 0;
int REPL_isLoop = 0;

void bfReplInterpret(char c) {
	switch (c) {
	case 43: {
		REPL_outArr[REPL_pointer_pos]++;
		break;
	}
	case 45: {
		REPL_outArr[REPL_pointer_pos]--;
		break;
	}
	case 46: {
		printf("%c", REPL_outArr[REPL_pointer_pos]);
		REPL_printing = 1;
		break;
	}
	case 44: {
		scanf("%c", &REPL_outArr[REPL_pointer_pos]);
		break;
	}
	case 60: {
		if (REPL_pointer_pos == 0) {
			REPL_pointer_pos = 3000;
		} else REPL_pointer_pos--;
		break;
	}
	case 62: {
		if (REPL_pointer_pos == 3000) {
			REPL_pointer_pos = 0;
		} else REPL_pointer_pos++;
		break;
	}
	case 91: {
		REPL_isLoop = 1;
		REPL_loop_start_pos = REPL_pointer_pos;
		break;
	}
	case 93: {
		REPL_loop_end_pos = 1;
		break;
	};
	}
}
void bfRepl() {
	char loopContent[10000];
	int loopContentLen = 0;
	while (1) {
		printf(">> ");
		char lines[100];
		scanf("%s", lines);
		if (!strcmp(lines, "exit")) {
			printf("Quitting process\n");
			break;
		}
		for (int i = 0; i < 100; i++) {
			if (lines[i] == '\0') {
				break;
			} else {
				bfReplInterpret(lines[i]);
				if (lines[i] == 91) { continue; }
			}
			if (REPL_isLoop && !REPL_loop_end_pos) {
				loopContent[loopContentLen] = lines[i];
				loopContentLen++;
			}
			if (REPL_isLoop && REPL_loop_end_pos) {
				while (REPL_outArr[REPL_loop_start_pos] != 0) {
					int i = 0;
					while (i < loopContentLen) {
						bfReplInterpret(loopContent[i]);
						i++;
					}
				}
				REPL_isLoop = 0;
				REPL_loop_end_pos = 0;
				REPL_loop_start_pos = 0;
				loopContentLen = 0;
				strcpy(loopContent, "");
			}
		}
		if (REPL_printing) {
			printf("\n");
			REPL_printing = 0;
		}
	}
}