#include <stdio.h>
#include <string.h>

char outArr[3000];
__U32_TYPE pointer_pos = 0;
__U32_TYPE loop_arr_pos = 0;
__U32_TYPE loop_start_pos = 0;
__U32_TYPE loop_end_pos = 0;
int isLoop = 0;

void bf(char c, int index) {
	switch (c) {
	case 43: {
		outArr[pointer_pos]++;
		break;
	}
	case 45: {
		outArr[pointer_pos]--;
		break;
	}
	case 46: {
		printf("%c", outArr[pointer_pos]);
		break;
	}
	case 44: {
		scanf("%c", &outArr[pointer_pos]);
		break;
	}
	case 60: {
		if (pointer_pos == 0) {
			pointer_pos = 3000;
		} else pointer_pos--;
		break;
	}
	case 62: {
		if (pointer_pos == 3000) {
			pointer_pos = 0;
		} else pointer_pos++;
		break;
	}
	case 91: {
		isLoop = 1;
		loop_arr_pos = pointer_pos;
		loop_start_pos = index;
		break;
	}
	case 93: {
		loop_end_pos = index;
		break;
	};
	}
}

int main(int args, char **options) {
	FILE *fptr;
	fptr = fopen(options[1], "r");
	if (fptr == 0) {
		printf("File not found");
		return 1;
	}
	char content[10240] = "";
	char lines[500];
	for (int i = 0; i < 3000; i++) { outArr[i] = 0; }
	while (fgets(lines, 500, fptr)) { strcat(content, lines); }
	for (int i = 0; i < 10240; i++) {
		if (content[i] == '\0') {
			continue;
		} else {
			bf(content[i], i);
		}
		if (isLoop && loop_end_pos) {
			while (outArr[loop_arr_pos] != 0) {
				for (int j = loop_start_pos + 1; j < loop_end_pos; j++) {
					bf(content[j], j);
				}
			}
			loop_end_pos = 0;
			isLoop = 0;
		}
	}
	printf("\n");
	fclose(fptr);
	return 0;
}
