#include "bitOperationVerify.h"


u32 abs_val_verify(i32 val) {
	return val >= 0 ? val : -val;
}


i32 negate_verify(i32 val) {
	return -val;
}


i32 bit_and_verify(i32 x, i32 y) {
	return x & y;
}

i32 bit_or_verify(i32 x, i32 y) {
	return x | y;
}

i32 bit_xor_verify(i32 x, i32 y) {
	return x ^ y;
}

bool is_INT_MAX_verify(i32 val) {
	return val == INT_MAX;
}

i32 bit_mask_verify(i8 high_bit, i8 low_bit) {
	i32 mask = 0;
	for (i8 i = low_bit; i <= high_bit; i++) {
		mask |= 1 << i;
	}
	return mask;
}

bool add_ok_verify(i32 x, i32 y) {
	i32 sum = x + y;
	if (x > 0 && y > 0 && sum <= 0) {
		return false;
	}
	if (x < 0 && y < 0 && sum >= 0) {
		return false;
	}
	return true;
}

i32 byte_swap_verify(i32 val, i8 n1, i8 n2) {
	i32 byte1 = (val >> (n1 * 8)) & 0xff;
	i32 byte2 = (val >> (n2 * 8)) & 0xff;

	i32 mask1 = 0xff << (n1 * 8);
	i32 mask2 = 0xff << (n2 * 8);
	i32 clear = val & ~(mask1 | mask2);
	return clear | (byte1 << (n2 * 8)) | (byte2 << (n1 * 8));
}

u8 bit_count_verify(i32 x) {
	u8 count = 0;
	while (x > 0) {
		count++;
		x &= x - 1;
	}
	return count;
}