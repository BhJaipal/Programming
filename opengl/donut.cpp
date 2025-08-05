#include <GL/gl.h>
#include <math.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <string.h>


struct Row {
	double a1, a2, a3;
	Row(float a = 0.0f, float b = 0.0f, float c = 0.0f): a1(a), a2(b), a3(c) {}
};

struct Matrix{
	Row a1, a2, a3;
};

struct singleRow: public Row {
	singleRow(float a = 0.0f, float b = 0.0f, float c = 0.0f): Row(a, b, c) {}

	singleRow multiply(Matrix m2) {
		singleRow res;
		res.a1 = (a1 * m2.a1.a1) + (a2 * m2.a2.a1) + (a3 * m2.a3.a1);
		res.a2 = (a1 * m2.a1.a2) + (a2 * m2.a2.a2) + (a3 * m2.a3.a2);
		res.a3 = (a1 * m2.a1.a3) + (a2 * m2.a2.a3) + (a3 * m2.a3.a3);
		return res;
	}
};

static void glfw_error_callback(int error, const char *description) {
	std::cerr << "Glfw Error " << error << description << "\n";
}
int WIDTH, HEIGHT = 400;
GLubyte* PixelBuffer = new GLubyte[WIDTH * HEIGHT * 3];
void makePixel(int x, int y, int r, int g, int b, GLubyte* pixels) {
    if (0 <= x && x < 200 && 0 <= y && y < 22) {
        int position = (x + y * 22) * 3;
        pixels[position] = r;
        pixels[position + 1] = g;
        pixels[position + 2] = b;
    }
}
int main() {
	glfwSetErrorCallback(glfw_error_callback);
	if (!glfwInit())
		return 1;

	const char* glsl_version = "#version 300 es";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	GLFWwindow *window = glfwCreateWindow(1280, 720, "Dear ImGui - Conan", NULL, NULL);
	if (window == NULL)
		return 1;
	glfwMakeContextCurrent(window);
	// Enable vsync
	glfwSwapInterval(1);
	float R2 = 2;
	float A = 0, B = 0, zBuffer[1760];

	while (!glfwWindowShouldClose(window)) {
		memset(zBuffer, 0, 7040);
		glfwPollEvents();
		for (float theta = 0; theta < 6.28; theta += 0.07) {
			for (float phi = 0; phi < 6.28; phi += 0.02) {
				singleRow circle(R2 + cos(theta), sin(theta), 0.0f);

				Matrix Ry = {{cos(phi), 0, sin(phi)}, {0, 1, 0}, {-sin(phi), 0, cos(phi)}};
				singleRow donut1 = circle.multiply(Ry);

				Matrix Rx = {{1, 0, 0}, {0, cos(A), sin(A)}, {0, -sin(A), cos(A)}};
				singleRow donut2 = donut1.multiply(Rx);

				Matrix Rz = {{cos(B), sin(B), 0}, {-sin(B), cos(B), 0}, {0, 0, 1}};
				// final result of spinning donut
				singleRow donut = donut2.multiply(Rz);


				float reciNz = 1 / (donut.a3 + 5);

				// x position
				int x = 40 + 30 * donut.a1 * reciNz;
				// y position
				int y = 12 + 15 * donut.a2 * reciNz;
				// current buffer index where current char has to be set
				int o = x + 80 * y;
				int L = 8 * (donut.a2 - donut.a3
					+ 2 * cos(B) * sin(A) * sin(phi)
					- 2 * cos(phi) * cos(theta) * sin(B)
					- 2 * cos(phi) * sin(B)
					+ 2 * cos(A) * sin(phi)
				);
				if (y < 22 && x < 80) {
					zBuffer[o] = L;
				}
			}
		}
		for (unsigned i = 0; i < 1760; i++) {
			PixelBuffer[i] = zBuffer[i];
		}
		makePixel(200, 200, 0, 0, 0, PixelBuffer);
		A += 0.00004;
		B += 0.00002;

		int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClearColor(0.45f, 0.55f, 0.60f, 1.00f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
