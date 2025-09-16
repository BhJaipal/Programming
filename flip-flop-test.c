#include "flip-flop.h"
#include <stdio.h>

int main() {
	bool bits = 0b01;

	printf("SR:\n");
	printf("+-----------------+--------------+\n");
	printf("|      Input      |     Output   |\n");
	printf("|  E  |  S  |  R  |  Qn  |  !Qn  |\n");
	printf("|-----+-----+-----+------+-------|\n");
	for (bool i = 0; i < 4; i++) {
		bool qn_1 = sr_flip_flop(1, i % 2, i / 2, bits);
		printf("|  1  |  %d  |  %d  |  %d   |   %d   |\n", i % 2, i / 2, qn_1 >> 1, qn_1 & 1);
	}
	printf("+-----+-----+-----+------+-------+\n");

	printf("\nDelay:\n");
	printf("+-----------+--------------+\n");
	printf("|   Input   |     Output   |\n");
	printf("|  E  |  D  |  Qn  |  !Qn  |\n");
	printf("|-----+-----+------+-------|\n");
	for (bool i = 0; i < 2; i++) {
		bool qn_1 = delay_flip_flop(1, i, bits);
		printf("|  1  |  %d  |  %d   |   %d   |\n", i, qn_1 >> 1, qn_1 & 1);
	}
	printf("+-----+-----+------+-------+\n");


	printf("\nJK:\n");
	printf("+-----------------+--------------+\n");
	printf("|      Input      |     Output   |\n");
	printf("|  E  |  J  |  K  |  Qn  |  !Qn  |\n");
	printf("|-----+-----+-----+------+-------|\n");
	for (bool i = 0; i < 4; i++) {
		bool qn_1 = jk_flip_flop(1, i % 2, i / 2, bits);
		printf("|  1  |  %d  |  %d  |  %d   |   %d   |\n", i % 2, i / 2, qn_1 >> 1, qn_1 & 1);
	}
	printf("+-----+-----+-----+------+-------+\n");


	printf("\nToggle:\n");
	printf("+-----------+--------------+\n");
	printf("|   Input   |     Output   |\n");
	printf("|  E  |  T  |  Qn  |  !Qn  |\n");
	printf("|-----+-----+------+-------|\n");
	for (bool i = 0; i < 2; i++) {
		bool qn_1 = toggle_flip_flop(1, i, bits);
		printf("|  1  |  %d  |  %d   |   %d   |\n", i, qn_1 >> 1, qn_1 & 1);
	}
	printf("+-----+-----+------+-------+\n");
}
