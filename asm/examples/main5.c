#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
	int fd = open("./data.out", O_RDONLY);
	struct stat statb;
	fstat(fd, &statb);
	printf("%ld %ld %ld %ld %ld %d %d %d %ld %ld\n\n", statb.st_dev, statb.st_size, statb.st_blocks, statb.st_blksize, statb.st_nlink, 
		statb.st_gid, statb.st_uid, statb.st_mode, statb.st_rdev, statb.st_ino);
	printf("%d %d %d\n", *(int*)&statb.st_atim, *(int*)&statb.st_ctim, *(int*)&statb.st_mtim);
	close(fd);
}
