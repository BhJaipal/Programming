#include "c-impl.h"
#include "syscall.h"

int main() {
	int fd = open("data.out", O_CREAT|O_RDWR, 0666);
	write(fd, "Hello From my libc\n", 19);
	close(fd);
}
