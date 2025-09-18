#include "../c-impl.h"
#include "syscall.h"

int main() {
	int fd = open("data.out", O_RDONLY, 0444);
	Stat statb;
	fstat(fd, &statb);
	write_uint(statb.st_dev);
	print(" ");
	write_uint(statb.st_size);
	print(" ");
	write_uint(statb.st_blocks);
	print(" ");
	write_uint(statb.st_blksize);
	print(" ");
	write_uint(statb.st_nlink);
	print(" ");
	write_uint(statb.st_gid);
	print(" ");
	write_uint(statb.st_uid);
	print(" ");
	write_uint(statb.st_mode);
	print(" ");
	write_uint(statb.st_rdev);
	print(" ");
	write_uint(statb.st_ino);
	println(" ");
	write_uint(*((int*)&statb.st_atim));
	print(" ");
	write_uint(*((int*)&statb.st_ctim));
	print(" ");
	write_uint(*((int*)&statb.st_mtim));
	close(fd);
}
