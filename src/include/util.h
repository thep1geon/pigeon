#ifndef __UTIL_H
#define __UTIL_H

#include "alias.h"
#include <stdio.h>

#define BYTE(n)     ((u64)n           * (u64)1)
#define KILOBYTE(n) ((u64)BYTE(n)     * (u64)1024)
#define MEGABYTE(n) ((u64)KILOBYTE(n) * (u64)1024)
#define GIGABYTE(n) ((u64)MEGABYTE(n) * (u64)1024)

#define LEN(arr) (sizeof(arr) / sizeof(*arr))
#define ARR(T, ...) ((T[]){__VA_ARGS__})

#define PRINT_FILE_LOC(fd) fprintf((fd), "[%s:%d] ", __FILE__, __LINE__)

#define TODO(...)           \
    PRINT_FILE_LOC(stdout); \
    printf(__VA_ARGS__)
    

#endif  //__UTIL_H
