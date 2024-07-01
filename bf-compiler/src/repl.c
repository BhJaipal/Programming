#include "repl.h"
#include <stdio.h>
#include <string.h>

void bfReplInterpret(char c, char outArr[30720], __U32_TYPE *pointer_pos,
					 __U32_TYPE *loop_start_pos, __U32_TYPE *loop_end_pos,
					 int *isLoop) {
	switch (c) {
	case 43: {
		if (loop_start_pos == pointer_pos) { outArr[*loop_start_pos]++; }
		outArr[*pointer_pos]++;
		break;
	}
	case 45: {
		if (loop_start_pos == pointer_pos) { outArr[*loop_start_pos]--; }
		outArr[*pointer_pos]--;
		break;
	}
	case 46: {
		printf("%c", outArr[*pointer_pos]);
		break;
	}
	case 44: {
		scanf("%c", &outArr[*pointer_pos]);
		break;
	}
	case 60: {
		if (*pointer_pos == 0) {
			*pointer_pos = 3000;
		} else *pointer_pos--;
		break;
	}
	case 62: {
		if (*pointer_pos == 3000) {
			*pointer_pos = 0;
		} else *pointer_pos++;
		break;
	}
	case 91: {
		*isLoop = 1;
		*loop_start_pos = *pointer_pos;
		break;
	}
	case 93: {
		*loop_end_pos = 1;
		break;
	};
	}
}
void bfRepl() {
	char outArr[30720];
	__U32_TYPE pointer_pos = 0;
	__U32_TYPE loop_start_pos = 0;
	__U32_TYPE loop_end_pos = 0;
	int isLoop = 0;
	while (1) {
		printf(">> ");
		char lines[100];
		char loopContent[10000];
		int loopContentLen = 0;
		scanf("%s", lines);
		if (!strcmp(lines, "exit")) {
			printf("Quitting process\n");
			break;
		}
		for (int i = 0; i < 100; i++) {
			if (lines[i] == '\0') {
				break;
			} else {
				bfReplInterpret(lines[i], outArr, &pointer_pos, &loop_start_pos,
								&loop_end_pos, &isLoop);
				if (lines[i] == 91) { continue; }
			}
			if (isLoop && !loop_end_pos) {
				loopContent[loopContentLen] = lines[i];
				loopContentLen++;
			}
			if (isLoop && loop_end_pos) {
				int i = 0;
				printf("%d\n", outArr[loop_start_pos]);
				while (outArr[loop_start_pos] != 0) {
					while (i < loopContentLen) {
						bfReplInterpret(loopContent[i], outArr, &pointer_pos,
										&loop_start_pos, &loop_end_pos,
										&isLoop);
						i++;
					}
				}
				isLoop = 0;
				loop_end_pos = 0;
				loop_start_pos = 0;
				loopContentLen = 0;
				strcpy(loopContent, "");
			}
		}
	}
}