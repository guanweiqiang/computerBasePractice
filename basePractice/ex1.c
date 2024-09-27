#include "ex1.h"



int pack_student_bytebybyte(Student* student, size_t count, char* buffer) {
	char* buffer_start = buffer;
	for (int i = 0; i < count; i++) {
		Student* s = student + i;
		for (int j = 0; j < 8; j++) {
			buffer_start[j] = s->name[j];
		}
		buffer_start += 8;
		for (int j = 0; j < 4; j++) {
			buffer_start[j] = (s->age >> (j * 8));
		}
		buffer_start += 4;
		for (int j = 0; j < 4; j++) {
			buffer_start[j] = *(((char*)&(s->score)) + j);
		}
		buffer_start += 4;
		for (int j = 0; j < 200; j++) {
			buffer_start[j] = s->remark[j];
		}
		buffer_start += 200;
	}
	return 1;
}


int unpack_student_bytebybyte(char* buf, size_t len, Student* student) {
	char* buffer_start = buf;
	int count = 0;

	while (len > 0 && count < 5) {
		Student* s = &student[count];
		memcpy(s->name, buffer_start, sizeof(s->name));
		buffer_start += sizeof(s->name);
		len -= sizeof(s->name);

		memcpy(&(s->age), buffer_start, sizeof(s->age));
		buffer_start += 4;
		len -= 4;

		memcpy(&(s->score), buffer_start, sizeof(s->score));
		buffer_start += sizeof(s->score);
		len -= sizeof(s->score);

		strcpy_s(s->remark, sizeof(char) * 200, buffer_start);
		buffer_start += sizeof(s->remark);
		len -= sizeof(s->remark);

		count++;
	}

	return count;  // 返回解压的人数
}

int pack_student_whole(Student* student, size_t count, char* buffer) {
	char* buffer_start = buffer;
	for (size_t i = 0; i < count; i++) {
		Student* s = student + i;

		memcpy(buffer_start, s->name, sizeof(s->name));
		buffer_start += 8;

		memcpy(buffer_start, (char*)&(s->age), sizeof(s->age));
		buffer_start += 4;

		memcpy(buffer_start, (char*)&(s->score), sizeof(s->score));
		buffer_start += 4;

		memcpy(buffer_start, s->remark, sizeof(s->remark));
		buffer_start += 200;
	}
	return 1;
}



void print_student(Student* student) {
	assert(student != NULL);
	printf("name: %s  ", student->name);
	printf("age: %d  ", student->age);
	printf("score: %.1f  ", student->score);
	printf("remark: %s  ", student->remark);
}