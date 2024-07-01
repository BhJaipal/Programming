#ifndef REPL_H
#define REPL_H
#include <stdio.h>

void bfReplInterpret(char c, char outArr[30720], __U32_TYPE *pointer_pos,
					 __U32_TYPE *loop_start_pos, __U32_TYPE *loop_end_pos,
					 int *isLoop);
void bfRepl();

#endif