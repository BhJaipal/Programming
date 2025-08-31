#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <EGL/egl.h>
#include <GL/gl.h>
#include <wayland-client-core.h>
#include <wayland-client-protocol.h>
#include <wayland-client.h>
#include <wayland-egl-core.h>
#include <gdk/wayland/gdkwayland.h>
#include <wayland-util.h>
#include <unistd.h>

#define DISPLAY WAY_CLIENT
#include "olive.h"
#include <fcntl.h>
#include <sys/mman.h>

#define HEIGHT 200
#define WIDTH 300
uint32_t pixels[WIDTH * HEIGHT];

struct wl_shell *shell = NULL;
struct wl_shm *wl_shm = NULL;
struct wl_compositor *compositor;

static void registry_add_object(void* data, struct wl_registry* registry, uint32_t name, const char* interface, uint32_t version) {
	printf("Name: %d, interface: %s, version: %d\n", name, interface, version);
	if (!strcmp(interface,"wl_compositor")) {
		compositor = wl_registry_bind (registry, name, &wl_compositor_interface, 1);
	}
	else if (!strcmp(interface, "gtk_shell1")) {
		shell = wl_registry_bind(registry, name, &wl_shell_interface, 1);
	}
	else if (!strcmp(interface,"wl_shm")) {
		wl_shm = wl_registry_bind (registry, name, &wl_shm_interface, 1);
	}
}

static void registry_remove_object(void* data, struct wl_registry* registry, uint32_t name){}
static struct wl_registry_listener registry_listener = {
    &registry_add_object,
    &registry_remove_object
};

static void shell_surface_ping (void *data, struct wl_shell_surface *shell_surface, uint32_t serial) {
	wl_shell_surface_pong (shell_surface, serial);
}
static void shell_surface_configure (void *data, struct wl_shell_surface *shell_surface, uint32_t edges, int32_t width, int32_t height) {}
static void shell_surface_popup_done (void *data, struct wl_shell_surface *shell_surface) {}
static struct wl_shell_surface_listener shell_surface_listener = {&shell_surface_ping, &shell_surface_configure, &shell_surface_popup_done};

void write_data() {
	fill_color_all(pixels, WIDTH, HEIGHT, 0xFFFFFFFF);
	fill_circle(pixels, WIDTH, HEIGHT, 150, 120, 20, 0xFF3F3F7F);
	fill_oval(pixels, WIDTH, HEIGHT, 50, 70, 20, 40, 0xFF00FF90);
	empty_oval(pixels, WIDTH, HEIGHT, 230, 50, 40, 20, 0xFF00FF90);
	fill_rect(pixels, WIDTH, HEIGHT, 50, 70, 60, 60, 0x20FF9000);
	empty_rect(pixels, WIDTH, HEIGHT, 200, 100, 60, 60, 0xFFFF9000);
	empty_circle(pixels, WIDTH, HEIGHT, 150, 50, 20, 0xFF3F3F7F);

	FILE *f = fopen("wayland-0", "wb");
	for (size_t i = 0; i < WIDTH * HEIGHT; i++) {
		fwrite(&pixels[i], 4, 1, f);
	}
	fclose(f);
}
typedef struct Window {
	EGLContext egl_context;
	struct wl_surface *surface;
	struct wl_shell_surface *shell_surface;
	struct wl_egl_window *egl_window;
	EGLSurface egl_surface;
} Window;
Window create_window(EGLDisplay display, int32_t width, int32_t height) {
	eglBindAPI(EGL_OPENGL_API);
	EGLint attributes[] = {
		EGL_RED_SIZE, 8,
		EGL_GREEN_SIZE, 8,
		EGL_BLUE_SIZE, 8,
	EGL_NONE};
	EGLConfig config;
	EGLint num_config;
	eglChooseConfig(display, attributes, &config, 1, &num_config);
	Window window = {0};
	window.egl_context = eglCreateContext(display, config, EGL_NO_CONTEXT, NULL);
	window.surface = wl_compositor_create_surface(compositor);
	window.shell_surface = wl_shell_get_shell_surface(shell, window.surface);
	wl_shell_surface_add_listener(window.shell_surface, &shell_surface_listener, &window);
	wl_shell_surface_set_toplevel(window.shell_surface);
	window.egl_window = wl_egl_window_create(window.surface, width, height);
	window.egl_surface = eglCreateWindowSurface(display, config, (EGLNativeWindowType)window.egl_window, NULL);
	eglMakeCurrent(display, window.egl_surface, window.egl_surface, window.egl_context);

	return window;
}

void draw(Window *window, EGLDisplay display) {
	glClearColor(0, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	eglSwapBuffers(window, window->egl_surface);
}
void destroy(Window *window, EGLDisplay egl_display, struct wl_display *display) {
	eglDestroySurface(egl_display, window->egl_surface);
	wl_egl_window_destroy(window->egl_window);
	wl_shell_surface_destroy(window->shell_surface);
	wl_surface_destroy(window->surface);
	eglDestroyContext(egl_display, window->egl_context);
	eglTerminate(egl_display);
	wl_display_disconnect(display);
}

int main() {
	// Setup
	struct wl_display *display = wl_display_connect(NULL);
	struct wl_registry *registry = wl_display_get_registry(display);
	wl_registry_add_listener(registry, &registry_listener, NULL);
	wl_display_roundtrip(display);

	EGLDisplay egl_display = eglGetDisplay(display);
	eglInitialize(egl_display, NULL, NULL);

	Window window = create_window(egl_display, WIDTH, HEIGHT);

	struct wl_region* r = wl_compositor_create_region(compositor);
	wl_region_add(r, 10, 20, 40, 40);

	// Memory pool
	int fd = open("wayland-0", O_RDONLY|O_EXCL);
	size_t size = WIDTH * HEIGHT * 4;
	if (fd == -1) {
		printf("Can't open wayland-0\n");
		exit(1);
	}

	uint32_t *data = mmap(NULL, size, PROT_WRITE | PROT_READ, MAP_SHARED, fd, 0);
	read(fd, data, size);
	ftruncate (fd, size);
	struct wl_shm_pool *pool = wl_shm_create_pool(wl_shm, fd, size);
	wl_shm_pool_set_user_data(pool, data);

	// create shell surface
	wl_shell_surface_set_user_data(window.shell_surface, window.surface);
	wl_surface_set_user_data(window.surface, NULL);
	wl_shell_surface_set_title(window.shell_surface, "Hello world");

	// Create Buffer
	struct wl_buffer *buff =  wl_shm_pool_create_buffer(pool, size, WIDTH, HEIGHT, WIDTH * 4, WL_SHM_FORMAT_ABGR8888);
	wl_surface_attach(window.surface, buff, 0, 0);
	wl_surface_commit(window.surface);
	close(fd);
	wl_buffer_destroy(buff);
	wl_shm_pool_destroy(pool);
	wl_shell_surface_set_title(window.shell_surface, "Hello world");

	while (1) {
		wl_display_dispatch(display);
		draw(&window, egl_display);
	}
	destroy(&window, egl_display, display);
	return 0;
}
