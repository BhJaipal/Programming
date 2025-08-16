#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
	int fd;
	char *data;

	data = mmap(NULL, 20, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	pid_t pid = fork();

	if(pid == 0) {
	    // Child process
		strcpy(data, "Hello World");
		exit(0);
	} else {
		wait(NULL);
		printf("Child wrote: %s", data);
		munmap(data, 20);
	}
	return 0;
}
