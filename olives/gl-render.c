#include <endian.h>
#include <GL/gl.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

int gl_render(uint32_t *pixels, size_t width, size_t height, char *title) {
	if (!glfwInit()) {
		perror("GLFW Init failed");
		return 1;
	}
	size_t n = width * height;
	for (size_t i = 0; i < n; i++) {
		uint8_t alpha = pixels[i] >> 24;
		pixels[i] <<= 8;
		pixels[i] += alpha;
		pixels[i] = htobe32(pixels[i]);
	}
	for (size_t i = 0; i < height; i++) {
		for (size_t j = 0; j < width / 2;j++) {
			size_t d = i * width + j,
					d2 = (i + 1) * width - j - 1;
			pixels[d] ^= pixels[d2];
			pixels[d2] ^= pixels[d];
			pixels[d] ^= pixels[d2];
		}
	}
	for (size_t i = 0; i < n / 2;i++) {
		pixels[i] ^= pixels[n-1-i];
		pixels[n-1-i] ^= pixels[i];
		pixels[i] ^= pixels[n-i-1];
	}
	GLFWwindow *window = glfwCreateWindow(width, height, title, NULL, NULL);
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glDrawPixels(width, height, GL_RGBA, GL_UNSIGNED_BYTE, pixels);
		glDrawArrays(GL_POINTS, 0, 1);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}
