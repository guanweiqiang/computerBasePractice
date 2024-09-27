#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "bitOperation.h"
#include "bitOperationVerify.h"
#include "ex1.h"
#include "myint.h"


#define N 5
#define N1 2
#define N2 3

int main(void) {
	

	Student student[N] = {
		{"Tom", 18, 90.0f, "Good student!"},
		{"Jerry", 19, 80.0f, "Good student!!"},
		{"Mickey", 20, 70.0f, "Good student!!!"},
		{"Minnie", 21, 60.0f, "Good student!!!!"},
		{"Donald", 22, 50.0f, "Good student!!!!!"}
	};
	
	char* buffer = (char*)malloc(sizeof(Student) * N);
	if (buffer == NULL) {
		perror("Faile to malloc for buffer!");
	}

	

	pack_student_bytebybyte(&student, N1, buffer);
	pack_student_whole(&student[N1], N2, buffer + sizeof(Student) * N1);
	assert(buffer != NULL);
	for (int i = 0; i < 20; i++) {
		printf("%x ", buffer[i]);
	}
	printf("\n");
	Student new_student[N];
	unpack_student_bytebybyte(buffer, sizeof(Student) * N, &new_student);
	for (size_t i = 0; i < N; i++)
	{
		print_student(new_student + i);
		printf("\n");
	}
	free(buffer);


	//// Test bit operation
	//i32 x = 0x12345678;
	//i32 y = 0x87654321;
	//i32 z = 0xabcdef00;
	//i32 w = 0xabcdef11;
	//i32 result = 0;
	//result = bit_and(x, y);
	//printf("0x%x & 0x%x = 0x%x\n", x, y, result);
	//result = bit_or(x, y);
	//printf("0x%x | 0x%x = 0x%x\n", x, y, result);
	//result = bit_xor(x, y);
	//printf("0x%x ^ 0x%x = 0x%x\n", x, y, result);
	//result = bit_mask(31, 0);
	//printf("bit_mask(31, 0) = 0x%x\n", result);
	//result = byte_swap(z, 0, 3);
	//printf("byte_swap(0x%x, 0, 3) = 0x%x\n", z, result);
	//result = bit_count(w);
	//printf("bit_count(0x%x) = %d\n", w, result);
	/*int x = 45683;
	assert(bit_count(x) != bit_count_verify(x));*/
	
	return 0;
}