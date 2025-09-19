#include "c-impl.h"
int do_test(int argc, char **argv);

int main(int argc, char *argv[]) {
	print("Testing ");
	print(argv[1]);
	println("...");

	int test_result = do_test(argc, argv);
	if (test_result) {
		print("\e[91mTest ");
		print(argv[1]);
		println(" Failed\e[0m");
	} else {
		print("\e[92mTest ");
		print(argv[1]);
		println(" Passed\e[0m");
	}
	return test_result;
}
