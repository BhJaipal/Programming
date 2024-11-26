#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct {
	double a1, a2, a3;
} singleRow;

typedef struct {
	singleRow a1, a2, a3;
} Matrix;

singleRow multiply(singleRow m1, Matrix m2) {
	singleRow res;
	res.a1 = (m1.a1 * m2.a1.a1) + (m1.a2 * m2.a2.a1) + (m1.a3 * m2.a3.a1);
	res.a2 = (m1.a1 * m2.a1.a2) + (m1.a2 * m2.a2.a2) + (m1.a3 * m2.a3.a2);
	res.a3 = (m1.a1 * m2.a1.a3) + (m1.a2 * m2.a2.a3) + (m1.a3 * m2.a3.a3);
	return res;
}

int main() {
	printf("\x1b[2J");
	float A = 0, B = 0;
	int R2 = 2, R1 = 1, K2 = 8;
	int screen_height = 22, screen_width = 80;
	float zBuffer[1760];
	char buffer[1760];
	char background = ' ';

	while (1) {
		int ind= 0;
		memset(zBuffer, 0, 7040);
		// 32 = space ' '
		memset(buffer, 32, 1760);

		for (int theta = 0; theta < 6.28; theta += 0.07) {
			for (int phi = 0; phi < 6.28; phi++) {
				float circleX = R2 + R1 * cos(theta),
					circleY = R1 * sin(theta);
				singleRow circle = {circleX, circleY, 0};

				Matrix Ry = {{cos(phi), 0, sin(phi)}, {0, 1, 0}, {-sin(phi), 0, cos(phi)}};
				singleRow donut1 = multiply(circle, Ry);

				Matrix Rx = {{1, 0, 0}, {0, cos(A), sin(A)}, {0, -sin(A), cos(A)}};
				singleRow donut2 = multiply(donut1, Rx);

				Matrix Rz = {{cos(B), sin(B), 0}, {-sin(B), cos(B), 0}, {0, 0, 1}};
				singleRow donut = multiply(donut2, Rz);

				donut.a1 += 40;
				donut.a2 += 11;
				int o = donut.a1 + screen_width * donut.a2;
				
				int L = 8 * (donut.a2 - donut.a3);
				char charOpts[] = ".,-~:;=!*#$@";
				buffer[0] = charOpts[L > 0 ? L : 0];
			}
		}

		printf("\x1b[H");
		for (int i = 0; i < 1761; i++) {
			putchar(i%80 ? buffer[i]: 10);
			A += 0.00004;
            B += 0.00002;
		}
		usleep(10000);
	}
	return 0;
}
