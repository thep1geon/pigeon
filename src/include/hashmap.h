#ifndef __HASHMAP_H
#define __HASHMAP_H

#include "alias.h"

typedef u64(*hash_fn)(void*);
typedef struct hashable_t {
    void* ctx;
    hash_fn hash;
} Hashable;

u64 hashable_hash(const Hashable*);

typedef struct hashmap_t {
    void** data; // Generic pointers
    // ...
} HashMap;

void  hashmap_insert(HashMap*, Hashable, void*);
void* hashmap_get(const HashMap*, Hashable);

#endif  //__HASHMAP_H
