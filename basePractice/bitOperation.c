#include "bitOperation.h"



u32 abs_val(i32 val) {
	i32 mask = val >> 31;
	return (val + mask) ^ mask;
}



i32 negate(i32 val) {
	return ~val + 1;
}

i32 bit_and(i32 x, i32 y) {
	return ~(~x | ~y);
}


i32 bit_or(i32 x, i32 y) {
	return ~(~x & ~y);
}

i32 bit_xor(i32 x, i32 y) {
	return ~(x & y) & ~(~x & ~y);
}

bool is_INT_MAX(i32 val) {
	return !((val + 1) ^ ((~val + 1) - 1));
}

i32 bit_mask(u8 high_bit, u8 low_bit) {
	i32 high_mask = (~0u) << high_bit;
	high_mask = ~high_mask;

	i32 low_mask = (~0u) << low_bit;
	return high_mask & low_mask;

}

bool add_ok(i32 x, i32 y) {
	bool overflow = x >> 31 ^ (x + y) >> 31;
	return x >> 31 ^ y >> 31 || !overflow;
}

i32 byte_swap(i32 val, i8 n1, i8 n2) {
	i32 byte1 = (val >> (n1 * 8)) & 0xff;
	i32 byte2 = (val >> (n2 * 8)) & 0xff;

	i32 mask1 = 0xff << (n1 * 8);
	i32 mask2 = 0xff << (n2 * 8);
	i32 clear = val & ~(mask1 | mask2);
	return clear | (byte1 << (n2 * 8)) | (byte2 << (n1 * 8));
}


u8 bit_count(i32 x) {
	u8 count = 0;

	count += (x & 0x55555555) + ((x >> 1) & 0x55555555); 
	count = (count & 0x33333333) + ((count >> 2) & 0x33333333);
	count = (count & 0x0f0f0f0f) + ((count >> 4) & 0x0f0f0f0f);
	count = (count & 0x00ff00ff) + ((count >> 8) & 0x00ff00ff); 
	count = (count & 0x0000ffff) + ((count >> 16) & 0x0000ffff); 

	return count;
}
