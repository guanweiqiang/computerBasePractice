#pragma once

#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "myint.h"

typedef struct {
	char name[8];
	short age;
	float score;
	char remark[200];
}Student;


int pack_student_bytebybyte(Student* student, size_t count, char* buffer);

int unpack_student_bytebybyte(char* buffer, size_t length, Student* student);

void print_student(Student* student);

int pack_student_whole(Student* student, size_t count, char* buffer);