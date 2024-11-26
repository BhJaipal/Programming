#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
	printf("\x1b[2J");
	float A = 0, B = 0;
	int screen_height = 22, screen_width = 80;
	float zBuffer[1760];
	char buffer[1760];
	char background = ' ';
	while (1) {
		memset(buffer, 32, 1760);
		memset(zBuffer, 0, 7040);
		for (float theta = 0; theta < 6.28; theta += 0.07) {
			for (float phi = 0; phi < 6.28; phi += 0.02) {
				char outPrint[] = ".,-~:;=!*#$@";
				float sP = sin(phi);
                float cT = cos(theta);
                float sA = sin(A);
                float circleY = sin(theta);
                float cA = cos(A);
				// (cos(θ) + 2)
                float circleX = cos(theta) + 2;
                float D = 1 / (sP * circleX * sA + circleY * cA + 5);
                float cP = cos(phi);
                float cB = cos(B);
                float sB = sin(B);

                float YsA_sPXcA =  circleY * sA - sP * circleX * cA;

				// x = 40 * 30 * (
				//      cos(φ) * circleX * cos(B)
				//      + (
				//          sin(φ) * circleX * cos(A)
				//          - sin(θ) * sin(A)
				//      ) * sin(B)
				//  ) / (sin(φ) * circleX * sin(A) * sin(θ) * cos(A) + 5)
                int x = 40 + 30 * D * (cP * circleX * cB - YsA_sPXcA * sB);

				// y = 12 + 15 * (
				//      cos(φ) * circleX * sin(B)
				//      + (
				//           sin(θ) * sin(A)
				//          - sin(φ) * circleX * cos(A)
				//      ) * cos(B)
				//  ) / (sin(φ) * circleX * sin(A) * sin(θ) * cos(A) + 5)
                int y = 12 + 15 * D * (cP * circleX * sB + YsA_sPXcA * cB);
                int o = x + 80 * y;

                int N = 8 * ((circleY * sA - sP * cT * cA) * cB - sP * cT * sA - circleY * cA - cP * cT * sB);

				if (screen_height > y && y > 0 && x > 0 && screen_width > x && D > zBuffer[o]) {
                    zBuffer[o] = D;
                    buffer[o] = outPrint[N > 0 ? N : 0];
                }
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
