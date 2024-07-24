#ifndef __ALLOCATOR_H
#define __ALLOCATOR_H

#include <pigeon/alias.h>

typedef void*(*alloc_fn)(void*,usize);

typedef struct Allocator Allocator;
struct Allocator {
    void* ptr;
    alloc_fn alloc;
};

Allocator allocator_new(void* ptr, alloc_fn fn);
Allocator allocator_malloc_new(void);
Allocator allocator_calloc_new(void);
void* alloc(Allocator allocator, usize n);

#endif  //__ALLOCATOR_H
