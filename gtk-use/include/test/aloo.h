#ifndef TEST_ALOO_H
#define TEST_ALOO_H
#include "../builtin/widget.h"

/******************** Private Funcs ********************/

struct _Test;

int __expectInt(int expected, int actual);
int __expectWidget(alooWidget *expected, alooWidget *actual);
int __expectGtkWidget(GtkWidget *expected, alooWidget *actual);
void __addTest(const char *test_name, struct _Test *test, int test_res);
void __testRes(struct _Test *t);

/******************** Private Types ********************/

typedef struct _Test {
	int (*expectInt)(int expected, int actual);
	int (*expectWidget)(alooWidget *expected, alooWidget *actual);
	int (*expectGtkWidget)(GtkWidget *expected, alooWidget *actual);
	void (*addTest)(const char *test_name, struct _Test *test, int test_res);
	void (*result)(struct _Test *t);
	int testCount;
	int testPassed;
	int testFailed;
	const char *label;
} Test;

Test *createTest(const char *name);

#endif // TEST_ALOO_H