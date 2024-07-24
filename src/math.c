#include "include/math.h"

f32 pow_f32(f32 base, i32 exp) {
    return exp <= 0 ? 1 : base * pow_f32(base, exp-1);
}

f64 pow_f64(f64 base, i32 exp) {
    return exp <= 0 ? 1 : base * pow_f64(base, exp-1);
}

i32 digits_i32(i32 num) {
    return num == 0 ? 0 : digits_i32(num/10) + 1;
}
