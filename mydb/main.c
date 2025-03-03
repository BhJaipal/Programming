#include <stdio.h>

void help(char *exe_name) {
	printf("%s [db_file]\n\n", exe_name);
	printf("-h/--help       Shows this help");
}

int main(int argc, char **argv) {
	if (argc == 1) {
		help(argv[0]);
	}
}
