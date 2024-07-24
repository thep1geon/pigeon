#include "include/allocator.h"

#include <stdlib.h>

Allocator allocator_new(void* ptr, alloc_fn fn) {
    return (Allocator) {
        .alloc = fn,
        .ptr = ptr
    };
}

static void* malloc__(void* self, usize n) {
    (void)self;
    return malloc(n);
}

static void* calloc__(void* self, usize n) {
    (void)self;
    return calloc(n, 1);
}

Allocator allocator_malloc_new(void) {
    return allocator_new(NULL, malloc__);
}

Allocator allocator_calloc_new(void) {
    return allocator_new(NULL, calloc__);
}

void* alloc(Allocator allocator, usize n) {
    return allocator.alloc(allocator.ptr, n);
}
