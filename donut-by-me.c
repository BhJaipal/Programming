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

struct Color {
	char ch;
	char color[12];
};
struct Color colors[] = {
	{'@', "\x1b[38;5;092m"},
	{'$', "\x1b[38;5;093m"},
	{'#', "\x1b[38;5;098m"},
	{'*', "\x1b[38;5;099m"},
	{'!', "\x1b[38;5;063m"},
	{'=', "\x1b[38;5;067m"},
	{';', "\x1b[38;5;068m"},
	{':', "\x1b[38;5;069m"},
	{'~', "\x1b[38;5;074m"},
	{'-', "\x1b[38;5;075m"},
	{',', "\x1b[38;5;080m"},
	{'.', "\x1b[38;5;081m"},
};

singleRow multiply(singleRow m1, Matrix m2) {
	singleRow res;
	res.a1 = (m1.a1 * m2.a1.a1) + (m1.a2 * m2.a2.a1) + (m1.a3 * m2.a3.a1);
	res.a2 = (m1.a1 * m2.a1.a2) + (m1.a2 * m2.a2.a2) + (m1.a3 * m2.a3.a2);
	res.a3 = (m1.a1 * m2.a1.a3) + (m1.a2 * m2.a2.a3) + (m1.a3 * m2.a3.a3);
	return res;
}

int main() {
	float A = 0, B = 0;
	int R2 = 2, R1 = 1;
	int screen_height = 22, screen_width = 80;
	float zBuffer[1760];
	char buffer[1760];

	printf("\x1b[2J");
	while (1) {
		memset(zBuffer, 0, 7040);
		// 32 = space ' '
		memset(buffer, 32, 1760);

		for (float theta = 0; theta < 6.28; theta += 0.07) {
			for (float phi = 0; phi < 6.28; phi += 0.02) {
				float circleX = R2 + R1 * cos(theta),
					circleY = R1 * sin(theta);
				singleRow circle = {circleX, circleY, 0};

				Matrix Ry = {{cos(phi), 0, sin(phi)}, {0, 1, 0}, {-sin(phi), 0, cos(phi)}};
				singleRow donut1 = multiply(circle, Ry);

				Matrix Rx = {{1, 0, 0}, {0, cos(A), sin(A)}, {0, -sin(A), cos(A)}};
				singleRow donut2 = multiply(donut1, Rx);

				Matrix Rz = {{cos(B), sin(B), 0}, {-sin(B), cos(B), 0}, {0, 0, 1}};
				// final result of spinning donut
				singleRow donut = multiply(donut2, Rz);

				// R1 / (Nz + 5)
				// 5 is distance or so IDK correctly
				float reciNz = R1 / (donut.a3 + 5);

				// x position
				int x = 40 + 30 * donut.a1 * reciNz;
				// y position
				int y = 12 + 15 * donut.a2 * reciNz;
				// current buffer index where current char has to be set
				int o = x + screen_width * y;

				// L = 8 * (
				//		(circleY * cosA * cosB - sinϕ * cosB * cosθ * sinA)
				//		- (circleY * sinA)
				//		- (sinϕ * cosθ * cosA)
				//		- (cosϕ * cosθ * sinB)
				//  )

				//  L = Ny - Nz
				//  	- 2 sinB cosϕ cosθ
				//  	- 2 sinB cosϕ
				//  	+ 2 cosB sinA sinϕ
				//  	+ 2 cosA sinϕ
				int L = 8 * (donut.a2 - donut.a3
					+ 2 * cos(B) * sin(A) * sin(phi)
					- 2 * cos(phi) * cos(theta) * sin(B)
					- 2 * cos(phi) * sin(B)
					+ 2 * cos(A) * sin(phi)
				);

				char charOpts[] = ".,-~:;=!*#$@";
				if (zBuffer[o] < reciNz && y < screen_height && x < screen_width) {
					// printf("%d ", L);
					buffer[o] = charOpts[L > 0 ? L : 0];
					zBuffer[o] = reciNz;
				}
			}
		}

		printf("\x1b[H");
		for (int i = 0; i < 1761; i++) {
			// printf("%d ", buffer[i]);
			if (i%80) {
				for (int j = 0; j < 12; j++) {
					if (colors[j].ch == buffer[i])
						printf("%s", colors[j].color);
				}
			}
			putchar(i%80 ? buffer[i]: 10);
			if (i%80) printf("\e[0m");
			A += 0.00004;
            B += 0.00002;
		}
		usleep(20000);
	}
	return 0;
}
