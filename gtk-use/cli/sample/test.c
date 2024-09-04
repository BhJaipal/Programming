#include "aloo.h"
#include <stdio.h>
AlooApplication *app;
Test *t;

static void activate() {
	alooWidget *label = Label.new("Hello World!");
	alooWidget *win = Window.new(app);
	Window.setChild(win, label);
	Window.setSize(win, 400, 300);
	Window.setTitle(win, "$appName");
	Window.show(win);
	Window.present(win);

	t->addTest("Widget Test", t, t->expectGtkWidget(label->child, label));
	t->result(t);

	Window.set_app_window(win, app);
	g_application_quit(G_APPLICATION(app->app));
}

int main(int argc, char **argv) {
	t = createTest("Testing");
	t->addTest("Test trying", t, t->expectInt(2 * 2, 4));

	struct alooAppOptions opts = NONE_FLAGS_OPTIONS(argc, argv);
	app = Application.create("com.aloo-test.$project", opts);
	Application.add_event_listener(app, "activate", activate);

	int status = Application.run(app);
	Application.unref(app);
	return 0;
}