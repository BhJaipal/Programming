/* syscalls */
extern void read(char *msg, int len);
extern void write(const char *msg, int len);
extern void exit(int status);

/* C implementation */
extern void putchar(char c);
extern int pow(int b, int e);
extern void write_uint(unsigned int x);
extern unsigned int read_uint();
extern void write_int(int x);
extern int read_int();

extern unsigned strlen(const char *str);

extern void print(const char *str);

extern void println(const char *str);

#define main() void _start()
