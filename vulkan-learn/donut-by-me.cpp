#include <glm/ext/matrix_float3x3.hpp>
#include <glm/ext/vector_float3.hpp>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <glm/vec3.hpp>
#include <glm/mat3x3.hpp>

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
				glm::vec3 circle = {circleX, circleY, 0};

				glm::mat3x3 Ry = {{cos(phi), 0, sin(phi)}, {0, 1, 0}, {-sin(phi), 0, cos(phi)}};
				glm::vec3 donut1 = Ry * circle;

				glm::mat3x3 Rx = {{1, 0, 0}, {0, cos(A), sin(A)}, {0, -sin(A), cos(A)}};
				glm::vec3 donut2 = Rx * donut1;

				glm::mat3x3 Rz = {{cos(B), sin(B), 0}, {-sin(B), cos(B), 0}, {0, 0, 1}};
				// final result of spinning donut
				glm::vec3 donut = Rz * donut2;

				// R1 / (Nz + 5)
				// 5 is distance or so IDK correctly
				float reciNz = R1 / (donut[2] + 5);

				// x position
				int x = 40 + 30 * donut[0] * reciNz;
				// y position
				int y = 12 + 15 * donut[1] * reciNz;
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
				int L = 8 * (donut[1] - donut[2]
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
