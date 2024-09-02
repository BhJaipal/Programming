#include "test/aloo.h"
#include "utils/error.h"

int __expectInt(int expected, int actual) {
	if (expected != actual) {
		throw_error("Expected int '%d', but got int '%d'", expected, actual);
		return 0;
	}
	return 1;
}

char *widgetStr(alooWidget *widget) {
	char *wid;
	switch (widget->type) {
	case ALOO_BOX: wid = "AlooBox"; break;
	case ALOO_BUTTON: wid = "AlooButton"; break;
	case ALOO_GRID: wid = "AlooGrid"; break;
	case ALOO_LABEL: wid = "AlooLabel"; break;
	case ALOO_WINDOW: wid = "AlooWindow"; break;
	case ALOO_NEW_WIDGET: wid = "AlooNewWidget"; break;
	default: break;
	}
	return wid;
}

int __expectWidget(alooWidget *expected, alooWidget *actual) {
	if (expected->child != actual->child ||
		(expected->type == ALOO_NEW_WIDGET || actual->type == ALOO_NEW_WIDGET ||
		 expected->type != actual->type)) {
		if (expected->child != actual->child)
			throw_error("Widgets are different");
		if (expected->type != ALOO_NEW_WIDGET &&
			actual->type != ALOO_NEW_WIDGET && actual->type != expected->type)
			throw_error("Expected widget '%s', but got widget '%s'",
						widgetStr(expected), widgetStr(actual));
		return 0;
	}
	return 1;
}
int __expectGtkWidget(GtkWidget *expected, alooWidget *actual) {
	alooWidget *out = Widget.gtk_to_aloo(expected);
	if (out->child != actual->child ||
		(out->type == ALOO_NEW_WIDGET || actual->type == ALOO_NEW_WIDGET ||
		 out->type != actual->type)) {
		if (out->child != actual->child) throw_error("Widgets are different");
		if (out->type != ALOO_NEW_WIDGET && actual->type != ALOO_NEW_WIDGET &&
			actual->type != out->type)
			throw_error("Expected widget '%s', but got widget '%s'",
						widgetStr(out), widgetStr(actual));
		return 0;
	}
	return 1;
}

void __addTest(const char *test_name, struct _Test *test, int test_res) {
	test->testCount++;
	if (test_res) {
		fprintf(stderr, "\033[1m%s: \033[1;32mPassed\033[0m\n\n", test_name);
		test->testPassed++;
	} else {
		fprintf(stderr, "\033[1m%s: \033[1;31mFailed\033[0m\n\n", test_name);
		test->testFailed++;
	}
}

void __testRes(struct _Test *t) {
	fprintf(stderr,
			"\n\033[1m%s Results:\033[0m\n"
			"\t\033[1mTotal Tests: %d\033[0m\n"
			"\t\t\033[1;32m%d Passed\033[0m\n"
			"\t\t\033[1;31m%d Failed\033[0m\t\t",
			t->label, t->testCount, t->testPassed, t->testFailed);
}

Test *createTest(const char *name) {
	Test *test = malloc(sizeof(Test));
	test->testCount = 0;
	test->testPassed = 0;
	test->testFailed = 0;
	test->expectGtkWidget = __expectGtkWidget;
	test->expectWidget = __expectWidget;
	test->expectInt = __expectInt;
	test->addTest = __addTest;
	test->result = __testRes;
	test->label = name;
	fprintf(stderr, "\r       \n");
	return test;
}
