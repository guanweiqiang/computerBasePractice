#pragma once

#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#include "myint.h"




u32 abs_val_verify(i32 val);

i32 negate_verify(i32 val);

i32 bit_and_verify(i32 x, i32 y);

i32 bit_or_verify(i32 x, i32 y);

i32 bit_xor_verify(i32 x, i32 y);

bool is_INT_MAX_verify(i32 val);

i32 bit_mask_verify(i8 high_bit, i8 low_bit);

bool add_ok_verify(i32 x, i32 y);

i32 byte_swap_verify(i32 val, i8 bit1, i8 bit2);

u8 bit_count_verify(i32 x);
	