/* syscalls */
extern void read(char *msg, int len);
extern void write(const char *msg, int len);
extern void exit(int status);
extern void* mmap(unsigned pos, long unsigned size);
extern void munmap();

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

extern void free(void *ptr);
// extern void* malloc(unsigned len);

#define main void _start()
#define end exit(0); }
#define null (void *)0
