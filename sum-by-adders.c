#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint8_t xor(uint8_t x, uint8_t y) {
	return (x || y) && (!(x && y));
}

typedef struct {
	uint8_t out, carry;
} AdderResult;

AdderResult halfAdder(uint8_t x, uint8_t y) {
	AdderResult res = {xor(x, y), x && y};
	return res;
}

AdderResult fullAdder(uint8_t x, uint8_t y, uint8_t carry) {
	AdderResult r;
	r.carry = ((x || y) && carry) || ((x || carry) && y);
	r.out = xor(xor(x, y), carry);
	return r;
}
const char *toBinary(uint8_t dec);

uint8_t add(uint8_t x, uint8_t y) {
	const char *xB = toBinary(x);
	const char *yB = toBinary(y);
	char bin[] = "00000000";

	AdderResult res = halfAdder(xB[7] - 48, yB[7] - 48);
	bin[7] += res.out;
	for (int i = 6; i >= 0; i--) {
		res = fullAdder(xB[i] - 48, yB[i] - 48, res.carry);
		bin[i] += res.out;
	}
	uint8_t out = 0;
	for (int i =0; i < 8; i++) {
		out *= 2;
		out += bin[i] - 48;
	}

	free((void *)xB);
	free((void *)yB);
	return out;
}

int main(int argc, char *argv[]) {
	uint8_t adderUse = add(0xa, 6);
	printf("10 + 6 = %d %b\n", adderUse, adderUse);
	return 0;
}

const char *toBinary(uint8_t dec) {
	char bin[] = "00000000";
	for (int i = 7; i >= 0; i--) {
		bin[i] = (char)(48 + (dec % 2));
		dec /= 2;
	}
	char *out = malloc(sizeof(char[9]));
	for (int i = 0; i < 9; i++) {
		out[i] = bin[i];
	}
	return out;
}
