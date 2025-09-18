#ifndef MY_SYSCALL_H
#define MY_SYSCALL_H
#include "types.h"

typedef enum {
	PROT_READ = 0x1,		/* Page can be read.  */
	PROT_WRITE= 0x2,		/* Page can be written.  */
	PROT_EXEC = 0x4,		/* Page can be executed.  */
	PROT_NONE = 0x0,		/* Page can not be accessed.  */
	PROT_GROWSDOWN =	0x01000000, /* Extend change to start of growsdown vma (mprotect only).  */
	PROT_GROWSUP	=	0x02000000, /* Extend change to start of growsup vma (mprotect only).  */
} PageProtection;

/* Sharing types (must choose one and only one of these).  */
typedef enum {
	MAP_SHARED =	0x01,		/* Share changes.  */
	MAP_PRIVATE=	0x02,		/* Changes are private.  */
	MAP_FIXED = 	0x10,		/* Interpret addr exactly.  */
	MAP_ANONYMOUS = 0x20,		/* Don't use a file.  */
} MapProps;

typedef enum {
	O_ACCMODE= 0003,
	O_RDONLY= 00,
	O_WRONLY= 01,
	O_RDWR= 02,
	O_CREAT= 0100,
	O_EXCL= 0200,
	O_NOCTTY= 0400,
	O_TRUNC= 01000,
	O_APPEND= 02000,
	O_NONBLOCK= 04000,
	O_NDELAY= O_NONBLOCK,
	O_SYNC= 04010000,
	O_FSYNC= O_SYNC,
	O_ASYNC= 020000,
	__O_LARGEFILE= 0100000,
	__O_DIRECTORY= 0200000,
	__O_NOFOLLOW= 0400000,
	__O_CLOEXEC= 02000000,
	__O_DIRECT= 040000,
	__O_NOATIME= 01000000,
	__O_PATH= 010000000,
	__O_DSYNC= 010000,
	__O_TMPFILE= (020000000 | __O_DIRECTORY)
} FileOpenFlags;

typedef struct {
	uint64 st_dev; /* Device */
	uint64 st_ino; /* File serial number */

    uint64 st_mode;		/* File mode.  */
    uint64 st_nlink;		/* Link count.  */

    uint64 st_uid; 	/* User ID of the file's owner.	*/
    uint64 st_gid; 	/* Group ID of the file's group.*/

    uint64 st_rdev;		/* Device number, if device.  */
    int64 st_size;			/* Size of file, in bytes.  */

    int64 st_blksize;	/* Optimal block size for I/O.  */
    int64 st_blocks;		/* Number 512-byte blocks allocated. */

    struct timespec st_atim;			/* Time of last access.  */
    struct timespec st_ctim;			/* Time of last status change.  */
    struct timespec st_mtim;			/* Time of last modification.  */
} Stat;

extern void read(int fd, char *msg, int len);
extern void write(int fd, const char *msg, int len);
extern int open(const char *path, FileOpenFlags flags, uint16 mode);
extern void close(int fd);
extern int stat(const char* path, Stat *statbuf);
extern int fstat(int fd, Stat *statbuf);
extern void *mmap (void *__addr, size_t __len, PageProtection __prot,
		   MapProps __flags, int __fd, long __offset);
extern void munmap(void *ptr, size_t size);
extern void exit(int status);

#endif // !MY_SYSCALL_H
