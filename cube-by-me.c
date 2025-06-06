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
	float A = 0, B = 0;
	int R2 = 2, R1 = 1;
	int screen_height = 22, screen_width = 80;
	float zBuffer[1760];
	char buffer[1760];
	char background = ' ';

	printf("\x1b[2J");
	while (1) {
		memset(zBuffer, 0, 7040);
		// 32 = space ' '
		memset(buffer, 32, 1760);
		float theta2 = 6.28;

		for (float theta = 0.01; theta < 6.28; theta += 0.07) {
			for (float phi = 0; phi < 6.28; phi += 1.57) {
				float circleX = R2 + R1 * sin(theta),
					circleY = R1 * sin(theta);
				singleRow square = {circleY, circleY, 0};

				Matrix Ry = {{cos(phi), 0, sin(phi)}, {0, 1, 0}, {-sin(phi), 0, cos(phi)}};
				singleRow cube2 = multiply(square, Ry);

				Matrix Rx = {{1, 0, 0}, {0, cos(A), sin(A)}, {0, -sin(A), cos(A)}};
				singleRow cube1 = multiply(cube2, Rx);
				
				Matrix Rz = {{cos(B), sin(B), 0}, {-sin(B), cos(B), 0}, {0, 0, 1}};
				// final result of spinning cube
				singleRow donut = multiply(cube1, Rz);

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
			theta2 -= 0.07;
		}

		printf("\x1b[H");
		for (int i = 0; i < 1761; i++) {
			// printf("%d ", buffer[i]);
			putchar(i%80 ? buffer[i]: 10);
			A += 0.00004;
            B += 0.00002;
		}
		usleep(20000);
	}
	return 0;
}
