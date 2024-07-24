#include "include/arena.h"
#include "include/allocator.h"
#include <assert.h>
#include <stdlib.h>

Arena arena_new() {
    char* buf = calloc(ARENA_MAX, 1);
    assert(buf);
    return (Arena) {
        .buffer = buf,
        .pos = buf,
    };
}

void arena_free(Arena* arena) {
    assert(arena);
    free(arena->buffer);
}

void* arena_alloc(Arena* arena, usize bytes) {
    void* ptr = (void*) arena->pos;
    arena->pos += bytes;
    return ptr;
}

static void* arena_alloc_(void* arena, usize bytes) {
    return arena_alloc((Arena*)arena, bytes);
}

void arena_dealloc(Arena* arena, usize bytes) {
    arena->pos -= bytes;
}

usize arena_get_pos(Arena* arena) {
    return (usize) (arena->pos - arena->buffer);
}

Allocator arena_to_allocator(Arena* arena) {
    return (Allocator) {
        .ptr = (void*) arena,
        .alloc = arena_alloc_,
    };
}
