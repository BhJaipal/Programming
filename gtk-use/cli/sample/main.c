#include "aloo.h"
AlooApplication *app;

static void activate() {
	alooWidget *label = Label.new("Hello World!");
	alooWidget *win = Window.new(app);
	Window.setChild(win, label);
	Window.setSize(win, 400, 300);
	Window.setTitle(win, "$appName");
	Window.show(win);
	Window.present(win);
	Window.set_app_window(win, app);
}

int main(int argc, char *argv[]) {
	struct alooAppOptions opts = NONE_FLAGS_OPTIONS(argc, argv);
	app = Application.create("com.example.hello", opts);
	Application.add_event_listener(app, "activate", activate);
	int status = Application.run(app);
	Application.unref(app);
	return 0;
}