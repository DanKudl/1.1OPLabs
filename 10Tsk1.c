#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRLEN 1024

typedef struct stud {
	char surname[STRLEN];
	char name[STRLEN];
	char birth[STRLEN];
	double birth_num;
	int marks[4];
	struct stud* next;
}sstud;


sstud* del(sstud* first)
{
	sstud* curr = first, * prev = NULL;
	while (curr)
	{
		if ((!prev) && ((curr->marks[0] != 2) && (curr->marks[1] != 2) && (curr->marks[2] != 2) && (curr->marks[3] != 2)))
		{
			first = curr->next;
		//	free(curr);
			curr = first;
			continue;
		}
		if ((curr->marks[0] != 2) && (curr->marks[1] != 2) && (curr->marks[2] != 2) && (curr->marks[3] != 2))
		{
			prev->next = curr->next;
		//	free(curr);
			curr = prev->next;
			continue;
		}
		prev = curr;
		curr = curr->next;
	}
	return first;
}

sstud* add_new_student(sstud* curr, sstud* first, sstud* last)
{
	char sur[STRLEN]; char name[STRLEN]; char birth[STRLEN];
	int m1, m2, m3, m4; double b_num;
	printf("\nNew student info: ");
	scanf("%s %s %s %d %d %d %d", sur, name, birth, &m1, &m2, &m3, &m4);

	double day = (birth[0] - '0') * 10 + (birth[1] - '0');
	double mouth = (birth[3] - '0') * 10 + (birth[4] - '0');
	double year = (birth[6] - '0') * 1000 + (birth[7] - '0') * 100 + (birth[8] - '0') * 10 + (birth[9] - '0');
	b_num = (year - 2000.0) * 12.0 + mouth + (day * (1.0 / 30.0));

	

	sstud* prev = NULL;

	sstud* new_student = (sstud*)malloc(sizeof(sstud));
	new_student->birth_num = b_num;
	strcpy(new_student->surname, sur);
	strcpy(new_student->name, name);
	strcpy(new_student->birth, birth);
	new_student->marks[0] = m1;
	new_student->marks[1] = m2;
	new_student->marks[2] = m3;
	new_student->marks[3] = m4;

	while (curr->next) {
		if (curr->birth_num > b_num) {
			if (curr) {
				if (prev) {
					prev->next = new_student;
					new_student->next = curr;
					return first;
				}
				else {
					new_student->next = curr;
					first = new_student;
					return first;
				}
			}
			else {
				last->next = new_student;
				return first;
			}
		}
		
		if (!prev) {
			prev = curr;
			curr = curr->next;
		}
		else {
			curr = curr->next;
			prev = prev->next;
		}
	}
	new_student->next = NULL;
	curr->next = new_student;
	return first;
	
}

void add_stud(sstud** prev, sstud* new_s, sstud** first) {
	if (*prev == NULL) {
		(*prev) = new_s;
		(*first) = new_s;
		return;
	}

	(*prev)->next = new_s;
	*prev = new_s;
	return;
}

sstud* read_stud(FILE* file)
{
	char str[STRLEN];
	int num = 0;
	sstud* new_stud = (sstud*)malloc(sizeof(sstud));
	

	fscanf(file, "%s", &str);
	strcpy(new_stud->surname, str);
	fscanf(file, "%s", &str);
	strcpy(new_stud->name, str);
	fscanf(file, "%s", &str);
	strcpy(new_stud->birth, str);
	
	if (isdigit(new_stud->surname[0])) {
		return NULL;
	}

	double day = (str[0] - '0') * 10 + (str[1] - '0');
	double mouth = (str[3] - '0') * 10 + (str[4] - '0');
	double year = (str[6] - '0') * 1000 + (str[7] - '0') * 100 + (str[8] - '0') * 10 + (str[9] - '0');
	double b_num = (year - 2000.0) * 12.0 + mouth + (day * (1.0 / 30.0));


	new_stud->birth_num = b_num;

	for (int i = 0; i < 4; i++)
	{
		fscanf(file, "%d", &num);
		new_stud->marks[i] = num;
	}
	new_stud->next = NULL;
	return new_stud;
}  

void print_data(sstud* first)
{
	sstud * curr = first;
	while (curr -> next)
	{
		printf("%-12s%-12s%-10s  %d %d %d %d\n", curr->surname, curr->name, curr->birth, curr->marks[0], 
			curr->marks[1], curr->marks[2], curr->marks[3]);
		curr = curr->next;
	}
	printf("%-12s%-12s%-10s  %d %d %d %d\n", curr->surname, curr->name, curr->birth, curr->marks[0],
		curr->marks[1], curr->marks[2], curr->marks[3]);
	return;
}

int main() {
	sstud* prev = NULL, * curr = NULL, * first = NULL;

	FILE* file = fopen("students.bin", "rb");

	while (!feof(file))
	{
		curr = read_stud(file);
		if(curr)
		add_stud(&prev, curr, &first);
	}
	(prev)->next = NULL;
	fclose(file);
	print_data(first);
	first = add_new_student(first, first, curr);
	print_data(first);
	printf("\n\nStudents with mark 2: \n\n");
    first = del(first);
    print_data(first);

	return 0;
}










