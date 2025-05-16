/* syscalls */
extern void read(char *msg, int len);
extern void write(const char *msg, int len);
extern void exit(int status);

/* C implementation */
extern void putchar(char c);
extern int pow(int b, int e);
extern void write_uint(unsigned int x);
extern unsigned int read_uint();
