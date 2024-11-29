#include <math.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

// Create struct single row for rows of matrix
// If you use object oriented, use class instead and make all members public
// singleRow = [a1, a2, a3]
typedef struct {
	double a1;
	double a2;
	double a3;
} singleRow;

// Now create a matrix class
// Matrix will contain 3 rows
// For java again use class and java does not have typedef
typedef struct {
	singleRow a1;
	singleRow a2;
	singleRow a3;
} Matrix;

// Now we will multiply 1*3 matrix with 3*3 matrix which will result in 1*3 matrix
// For Java users, add this method to a class and make it public static
// This function will help use in multpilication with rotation matrices
singleRow multiply(singleRow m1, Matrix m2) {
	singleRow res;
	res.a1 = m1.a1 * m2.a1.a1 + m1.a2 * m2.a2.a1 + m1.a3 * m2.a3.a1;
	res.a2 = m1.a1 * m2.a1.a2 + m1.a2 * m2.a2.a2 + m1.a3 * m2.a3.a2;
	res.a3 = m1.a1 * m2.a1.a3 + m1.a2 * m2.a2.a3 + m1.a3 * m2.a3.a3;
	return res;
}

int main() {
	// w * h = 1760
	int screen_width = 80, height = 22;
	// our donut characters will be stored in this array
	char buffer[1760];
	float zBuffer[1760];
	// A is angle for rotation along X-axis, B is for rotation along Z-axis
	float A = 0, B = 0;
	// R1 is radius of circle for donut, R2 is distance of circle from Y-axis
	int R2 = 2, R1 = 1;
	// Creates a new screen 
	printf("\x1b[2J");
	while (1) {
		// Fill buffer with spaces
		memset(buffer, ' ', 1760);
		// as float takes 4 bytes, 4 * 1760 = 7040
		// fill buffer with 0
		memset(zBuffer, 0, 7040);

		// circle require theta
		// It was so slow because there where 00 in 0.007 and 0.002
		// make them one
		for (float theta = 0; theta < 6.28; theta += 0.07) {
			// When we will rotate circle on Y-axis, It will create donut, rotation on Y require phi
			for (float phi = 0; phi < 6.28; phi += 0.02) {
				// To create a circle, On XY, there is equation r(cos theta + sin theta)
				// r = R1
				// R2 is from centre for Y-axis distance
				// We will make circle away from Y-axis by R2 distance
				singleRow circle = {2 + cos(theta), sin(theta), 0};
				// rotation on Y-axis
				Matrix Ry = {{cos(phi), 0, sin(phi)}, {0, 1, 0}, {-sin(phi), 0, cos(phi)}};
				// rotation on X-axis
				Matrix Rx = {{1, 0, 0}, {0, cos(A), sin(A)}, {0, -sin(A), cos(A)}};
				// rotation on Z-axis
				Matrix Rz = {{cos(B), sin(B), 0}, {-sin(B), cos(B), 0}, {0, 0, 1}};

				singleRow donut = multiply(circle, Ry);
				singleRow rotateX = multiply(donut, Rx);
				// We will consider it as [Nx, Ny, Nz]
				singleRow spinningDonut = multiply(rotateX, Rz);
				// Now our donut is spinning in both X and Z-axis


				// 5 is distance of camera from origin
				float reciNz = 1 / (spinningDonut.a3 + 5);

				// why is there Nz in division, IDK
				// screen_height / 2 should have been 11 but we will go with 12 for Now
				// what are 30 and 15? IDK
				// and multiply reciNz instead of division from Nz
				int x = 40 + 30 * spinningDonut.a1 * reciNz;
				int y = 12 + 15 * spinningDonut.a2 * reciNz;

				// o is index of current buffer
				int o = x + screen_width * y;

				// L is luminicity index, it will be in 0 to root(2) so we will multiply with 8
				int L = 8 * (spinningDonut.a2 - spinningDonut.a3 + 2 * cos(B) * sin(A) * sin(phi)
					- 2 * cos(phi) * cos(theta) * sin(B)
					- 2 * cos(phi) * sin(B)
					+ 2 * cos(A) * sin(phi)
				);

				// donut luminicity will be seen by these characters
				// these 12
				char charOut[] = ".,-~:;=!*#$@";

				if (x < screen_width && y < height && zBuffer[o] < reciNz) {
					zBuffer[o] = reciNz;
					// If L < 0, . will be buffer
					buffer[o] = charOut[L > 0 ? L : 0];
				}
			}
		}
		// Clear screen
		printf("\x1b[H");

		for (int i = 0; i <1761; i++) {
			// On every 80th character, new line will be printed
			// If there's a reminder then buffer printed
			putchar(i % 80 ? buffer[i] : 10);
			A += 0.00004;
			B += 0.00002;
		}
		// Timer to slow down speed a bit
		usleep(10000);

	}
}
