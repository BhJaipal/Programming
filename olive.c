/*
 * This is inspired from https://github.com/tsoding/olive.c, A recreational programmer
 * Who makes awesome C, rust content
 * Recommended to watch
 * https://youtube.com/@tsoding
 */
#include <errno.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

#define HEIGHT 400
#define WIDTH 300
uint32_t pixels[HEIGHT * WIDTH];

void merge_color(uint32_t *pixel_loc, size_t color) {
	if (color >> 8*3 == 0xFF) {
		*pixel_loc = color;
		return;
	}
	float alpha_percent = (float)(color >> 8*3) / 255;
	uint32_t out = 0xFF00;
	out += ((*pixel_loc >> 8 * 2) & 0xFF) * (1-alpha_percent) + ((color >> 8 * 2) & 0xFF) * (alpha_percent);
	out <<= 8;
	out += ((*pixel_loc >> 8) & 0xFF) * (1-alpha_percent) + ((color >> 8) & 0xFF) * (alpha_percent);
	out <<= 8;
	out += (*pixel_loc & 0xFF) * (1-alpha_percent) + (color & 0xFF) * (alpha_percent);
	*pixel_loc = out;
}

void fill_oval(uint32_t *pixels, size_t width, size_t height, size_t cx, size_t cy, size_t a, size_t b, uint32_t color) {
	size_t x = cx - a,
			y = cy - b;
	for (size_t d = 0; d < height * width; d++) {
		if (d == 0) {
			d = (cx - a) * (cy - b);
			continue;
		}
		if (d == width * (cx + a) * (cy + b)) break;
		size_t i = d / width,
			j = d % width;
		if (1 >= ((float)((j - cx) * (j - cx))/(a * a) + (float)((i - cy) * (i - cy))/(b*b))) // 1 = x^2/a^2 + y^2/b^2
		{
			if (color >> 24 != 0xFF) merge_color(&pixels[width * i + j], color);
			else pixels[width * i + j] = color;
		}
	}
}
void empty_oval(uint32_t *pixels, size_t width, size_t height, size_t cx, size_t cy, size_t a, size_t b, uint32_t color) {
	size_t x = cx - a,
			y = cy - b;
	for (size_t d = 0; d < height * width; d++) {
		if (d == 0) {
			d = (cx - a) * (cy - b);
			continue;
		}
		if (d == width * (cx + a) * (cy + b)) break;
		size_t i = d / width,
			j = d % width;
		if (
			(1 >= ((float)((j - cx) * (j - cx))/(a * a + a) + (float)((i - cy) * (i - cy))/(b*b + b))) &&
			(1 <= ((float)((j - cx) * (j - cx))/(a * a - a) + (float)((i - cy) * (i - cy))/(b*b - b)))
		)
			pixels[width * i + j] = color;
	}
}

void fill_circle(uint32_t *pixels, size_t width, size_t height, size_t cx, size_t cy, size_t r, uint32_t color) {
	size_t x = cx - r,
			y = cy - r;
	for (size_t d = 0; d < height * width; d++) {
		if (d == 0) {
			d = (cx - r) * (cy - r);
			continue;
		}
		if (d == width * (cx + r) * (cy + r)) break;
		size_t i = d / width,
			j = d % width;
		if (r * r >= ((i - cy) * (i - cy) + (j - cx) * (j - cx)))		// x^2 + y^2 = r^2
		{
			if (color >> 24 != 0xFF) merge_color(&pixels[width * i + j], color);
			else pixels[width * i + j] = color;
		}
	}
}
void empty_circle(uint32_t *pixels, size_t width, size_t height, size_t cx, size_t cy, size_t r, uint32_t color) {
	size_t x = cx - r,
			y = cy - r;
	for (size_t d = 0; d < height * width; d++) {
		if (d == 0) {
			d = (cx - r) * (cy - r);
			continue;
		}
		if (d == width * (cx + r) * (cy + r)) break;
		size_t i = d / width,
			j = d % width;
		if (
			(r * r + r >= ((i - cy) * (i - cy) + (j - cx) * (j - cx)))
			&& (r * r - r <= ((i - cy) * (i - cy) + (j - cx) * (j - cx)))
		)
			pixels[width * i + j] = color;
	}
}

void fill_rect(uint32_t *pixels, size_t width, size_t height, size_t x, size_t y, size_t w, size_t h, uint32_t color) {
	for (size_t d = 0; d < h * w; d++) {
		size_t i = d / w,
			j = d % w;
		if (color >> 24 != 0xFF) merge_color(&pixels[width * (y + i) + j + x], color);
		else pixels[width * (y + i) + j + x] = color;
	}
}
void empty_rect(uint32_t *pixels, size_t width, size_t height, size_t x, size_t y, size_t w, size_t h, uint32_t color) {
	for (size_t d = 0; d < h * w; d++) {
		size_t i = d / w,
			j = d % w;
		if ((j >= 0 && j <= w - 1) && (i == 0 || i == h - 1))
			pixels[(width * (i + y)) + j + x] = color;
		else if ((j == 0 || j == w - 1) && (i >= 0 && i <= h - 1))
			pixels[(width * (i + y)) + x + j] = color;
	}
}

void fill_color_all(uint32_t *pixels, size_t width, size_t height, uint32_t color) {
	for (uint64_t i = 0; i < width * height; i++) {
		pixels[i] = color;
	}
}
#define defer_ret(val) do { res = val; goto ret; } while(0);

int dump_pixel_to_ppm(uint32_t *pixels, size_t width, size_t height, char *file_path) {
	FILE *f = fopen(file_path, "wb");
	int res = 0;
	if (!f) defer_ret(-1);
	fprintf(f, "P6\n%zu %zu\n255\n", width, height);
	for (size_t i = 0; i < width * height; i++) {
		uint8_t pixel[] = {
			(pixels[i] >> 16) & 0xff,
			(pixels[i] >> 8) & 0xff,
			pixels[i] & 0xff,
		};
		fwrite(pixel, sizeof(pixel), 1, f);
		if (ferror(f)) defer_ret(errno);
	}

ret:
	if (f) fclose(f);
	return res;
}

int main() {
	fill_color_all(pixels, WIDTH, HEIGHT, 0xFFFFFFFF);
	fill_circle(pixels, WIDTH, HEIGHT, 150, 150, 20, 0xFF3F3F7F);
	fill_oval(pixels, WIDTH, HEIGHT, 70, 100, 20, 40, 0xFF00FF90);
	empty_oval(pixels, WIDTH, HEIGHT, 70, 200, 40, 20, 0xFF00FF90);
	fill_rect(pixels, WIDTH, HEIGHT, 70, 100, 60, 60, 0x20FF9000);
	empty_rect(pixels, WIDTH, HEIGHT, 150, 200, 60, 60, 0xFFFF9000);
	empty_circle(pixels, WIDTH, HEIGHT, 200, 100, 20, 0xFF3F3F7F);
	dump_pixel_to_ppm(pixels, WIDTH, HEIGHT, "see.ppm");
}
