#ifndef __ARENA_H
#define __ARENA_H

#include "allocator.h"
#include "util.h"

#define ARENA_MAX MEGABYTE(4)

typedef struct arena_t {
    char* buffer;
    char* pos;
} Arena;

Arena arena_new();
void arena_free(Arena* arena);
Allocator arena_to_allocator(Arena* arena);

void* arena_alloc(Arena* arena, usize bytes);
void arena_dealloc(Arena* arena, usize bytes);
usize arena_get_pos(Arena* arena);

#endif  //__ARENA_H
