#include "c-impl.h"
#include "tinyalloc.h"

typedef struct Block Block;

struct Block {
    void *addr;
    Block *next;
    size_t size;
};
typedef struct {
    Block *free;   // first free block
    Block *used;   // first used block
    Block *fresh;  // first available blank block
    size_t top;    // top free addr
} Heap;

main {
	Heap h;
	ta_init(&h, null, 256, 16, 8);
	char *name = ta_alloc(5);
	name[0] = 0x4a;
	name[1] = 0x61;
	name[2] = 0x69;
	name[3] = 0x0a;
	name[4] = 0x0;
	print(name);
	ta_free(name);
end
