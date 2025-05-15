extern void write(const char *msg, int len);
extern void exit(int len);

int _start() {
	write("Hello World", 12);
	exit(0);
	return 0;
}
