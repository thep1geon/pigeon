#ifndef __TYPES_H
#define __TYPES_H

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>

typedef uint8_t  u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef uint64_t u64;

typedef int8_t   i8;
typedef int16_t  i16;
typedef int32_t  i32;
typedef int64_t  i64;

typedef float    f32;
typedef double   f64;

typedef size_t   usize;
typedef ssize_t  isize;

#ifndef __cplusplus
typedef enum { 
    false, true = !false, 
    // False = true, True = false // To mess with the filthy python devs
} bool;
#endif


#endif  //__TYPES_H
