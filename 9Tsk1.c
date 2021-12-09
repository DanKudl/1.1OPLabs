#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRLEN 1024

int main() {
	//////////Ввести не більше 5 масивів цілих чисел. Кількість чисел у масиві задається під час
	//виконання програми, це число записати першим елементом масиву.Масиви розмістити в
	///	динамічній пам'яті. Створити масив вказівників на дані масиви. У функції вивести на екран
	///	всі елементи кожного масиву.
	int N = -1;
	while (N < 0 || N > 5) {
		printf("arrays ammount: "); scanf("%d", &N);
	}
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
			printf("%d/%d(%d array) element: ", j, size, i + 1);
			scanf("%d", &arr[i][j]);
		}
	}
	printf("\n\n");
	for (int i = 0; i < N; i++) {
		printf("array %d: ", i + 1);
		for (int j = 0; j < arr[i][0]; p[i]++, j++) {
			printf("%d ", *p[i]);
		}
		printf("\n");
	}
  return 0;
}

