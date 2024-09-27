#pragma once
#ifndef BIT_OPERATION_H

#include <stdio.h>
#include <inttypes.h>
#include <stdint.h>
#include <stdbool.h>
#include "myint.h"




u32 abs_val(i32 val);

i32 negate(i32 val);

i32 bit_and(i32 x, i32 y);

i32 bit_or(i32 x, i32 y);

i32 bit_xor(i32 x, i32 y);

bool is_INT_MAX(i32 val);

i32 bit_mask(u8 high_bit, u8 low_bit);

bool add_ok(i32 x, i32 y);

i32 byte_swap(i32 val, i8 bit1, i8 bit2);

u8 bit_count(i32 x);

#endif // !BIT_OPERATION_H
