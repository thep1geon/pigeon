#ifndef __MATH_H
#define __MATH_H

// I know there is a math library, but I don't want to link with that math
// library for a few functions. If this part of my library gets too big, I will
// start using the math.h implementations

#define PI (3.14159265358979323)
#define PI_2 (PI * 2)
#define PI_3 (PI * 3)
#define TAU (PI_2)
#define RAD(d) ((d) * (PI/180))
#define DEG(r) ((r) * (180/PI))

#include "alias.h"

f32 pow_f32(f32 base, i32 exp);
f64 pow_f64(f64 base, i32 exp);

// Returns the number of digits in a given integer
i32 digits_i32(i32 num);

#endif  //__MATH_H
