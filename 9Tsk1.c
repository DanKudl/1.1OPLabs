
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRLEN 1024


void output(int** p, int n) {
	printf("\n\n");
	for (int i = 0; i < n; i++) {
		printf("array %d: ", i + 1, p[i][0]);

		for (int j = 0; j < p[i][0]; j++) {
			printf("%+d ", p[i][j]);
		}
		printf("\n");
	}
}

int main(int argc, char* argv[]) {
	//////////Ввести не більше 5 масивів цілих чисел. Кількість чисел у масиві задається під час
	//виконання програми, це число записати першим елементом масиву.Масиви розмістити в
	///	динамічній пам'яті. Створити масив вказівників на дані масиви. У функції вивести на екран
	///	всі елементи кожного масиву.
	
	printf("amount of arrays: %s\n", argv[1]);
	int N = atoi(argv[1]);
	
	int** arr = (int**)calloc(N, sizeof(int*));
	int** p = (int**) calloc(N, sizeof(int*));
	int size;
	for (int i = 0; i < N; i++) {
		printf("array %d size: ", i + 1); 
		scanf("%d", &size);
		arr[i] = (int*)calloc(size, sizeof(int));
		p[i] = arr[i];
		arr[i][0] = size;
		for (int j = 1; j < size; j++) {
			printf("%d/%d(%d array) element: ", j + 1, size, i + 1);
			scanf("%d", &arr[i][j]);
		}
	}
	output(p, N);
	free(arr);
	free(p);
	for (int i = 0; i < N; i++) {
		free(arr[i]);
	}
	arr = NULL;
	p = NULL;
	return 0;
}



