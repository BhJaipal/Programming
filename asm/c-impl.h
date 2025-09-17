typedef unsigned long size_t;

typedef enum {
	PROT_READ = 0x1,		/* Page can be read.  */
	PROT_WRITE= 0x2,		/* Page can be written.  */
	PROT_EXEC = 0x4,		/* Page can be executed.  */
	PROT_NONE = 0x0,		/* Page can not be accessed.  */
	PROT_GROWSDOWN =	0x01000000, /* Extend change to start of growsdown vma (mprotect only).  */
	PROT_GROWSUP	=	0x02000000, /* Extend change to start of growsup vma (mprotect only).  */
} MemPermission;

/* Sharing types (must choose one and only one of these).  */
typedef enum {
	MAP_SHARED =	0x01,		/* Share changes.  */
	MAP_PRIVATE=	0x02,		/* Changes are private.  */
	MAP_FIXED = 	0x10,		/* Interpret addr exactly.  */
	MAP_ANONYMOUS = 0x20,		/* Don't use a file.  */
} MapProps;

/* syscalls */
extern void read(char *msg, int len);
extern void write(const char *msg, int len);
extern void exit(int status);
extern void *mmap (void *__addr, size_t __len, MemPermission __prot,
		   MapProps __flags, int __fd, long __offset);
extern void munmap(void *ptr, size_t size);

/* C implementation */
extern void putchar(char c);
extern int pow(int b, int e);
extern void write_uint(unsigned int x);
extern unsigned read_uint();
extern void write_int(int x);
extern int read_int();

extern unsigned strlen(const char *str);

extern void print(const char *str);

extern void println(const char *str);

extern void* malloc(size_t size);
extern void free(void *ptr);

#define null (void *)0
