#ifndef TYPES_H
#define TYPES_H

#define INT_TYPE(T, BITS) \
	typedef T int##BITS;  \
	typedef unsigned T uint##BITS;

INT_TYPE(char, 8);
INT_TYPE(short, 16);
INT_TYPE(int, 32);
INT_TYPE(long, 64);

typedef unsigned long size_t;

#endif // !TYPES_H
