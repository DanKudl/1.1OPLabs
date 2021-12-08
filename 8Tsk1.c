#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRLEN 1024

struct stud {
	char surname[STRLEN];
	char name[STRLEN];
	char birth[STRLEN];
	double birth_num;
	int marks[4];
};

int main()
{
	int day, mouth, year;
	int count = 0;
	struct stud students[30];
	struct stud students_with_good_marks[30];
	char str[STRLEN];
	FILE* file = fopen("students.txt", "r");

	char* p;
	while (!feof(file))
	{
		fgets(str, STRLEN, file);

		p = strtok(str, "\t");
		strcpy(students[count].surname, p);

		p = strtok(NULL, "\t");
		strcpy(students[count].name, p);

		p = strtok(NULL, "\t");// p = 11.11.2004
		strcpy(students[count].birth, p);
		day = (p[0] - '0') * 10 + (p[1] - '0');
		mouth = (p[3] - '0') * 10 + (p[4] - '0');
		year = (p[6] - '0') * 1000 + (p[7] - '0') * 100 + (p[8] - '0') * 10 + (p[9] - '0');
		students[count].birth_num = (year - 2000.0) * 12.0 + mouth + (day * (1.0 / 30.0));

		for (int i = 0; i < 4; i++) {
			p = strtok(NULL, " ");
			int x = atoi(p);
			students[count].marks[i] = x;
		}
		count++;
	}
	printf("Surname     Name        Birth       Marks\n-------------------------------------------\n"); 
	for (int i = 0; i < count; i++) {
		printf("%-12s%-12s%-10s  %d %d %d %d\n", students[i].surname, students[i].name, students[i].birth, students[i].marks[0], students[i].marks[1], students[i].marks[2], students[i].marks[3]);
	}
	printf("-------------------------------------------\n");
	int pr, gm_counter = 0;
	for (int i = 0; i < count; i++) {
		pr = 1;
		for (int j = 0; j < 4; j++) {
			if (students[i].marks[j] < 4) pr = 0;
		}
		if (pr != 0) {
			students_with_good_marks[gm_counter] = students[i];
			gm_counter++;
		}
	}

	if (gm_counter == 0) return 0;

	printf("\n\n       Students with only 4/5 marks:\n-------------------------------------------\n");
	double min_bn = students_with_good_marks[0].birth_num;
	int ind = 0;

	struct stud temp;

	for (int i = 0; i < gm_counter; i++) {
		for (int j = i; j < gm_counter; j++) {
			if (students_with_good_marks[j].birth_num < min_bn) {
				min_bn = students_with_good_marks[j].birth_num;
				ind = j;
			}
		}
		//swap
		temp = students_with_good_marks[ind];
		students_with_good_marks[ind] = students_with_good_marks[i];
		students_with_good_marks[i] = temp;
		//reset
		min_bn = students_with_good_marks[i + 1].birth_num;
		ind = i + 1;
	}

	for (int i = 0; i < gm_counter; i++) {
		printf("%-12s%-12s%-10s  %d %d %d %d\n", students_with_good_marks[i].surname,
			students_with_good_marks[i].name, students_with_good_marks[i].birth,
			students_with_good_marks[i].marks[0], students_with_good_marks[i].marks[1], 
			students_with_good_marks[i].marks[2], students_with_good_marks[i].marks[3]);
	}
	printf("-------------------------------------------\n\n             Youngest of them:\n-------------------------------------------\n");
	for (int i = gm_counter - 2; i < gm_counter; i++) {
		if (i > -1) {
			printf("%-12s%-12s%-10s  %d %d %d %d\n", students_with_good_marks[i].surname,
				students_with_good_marks[i].name, students_with_good_marks[i].birth,
				students_with_good_marks[i].marks[0], students_with_good_marks[i].marks[1],
				students_with_good_marks[i].marks[2], students_with_good_marks[i].marks[3]);
		}
	}
	printf("-------------------------------------------\n\n\n\n");
	return 0;
}
