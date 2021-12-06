#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
//#include "functions.h"

#define SIZE 100000

void swap(int* pos1, int* pos2)
{
    int tmp = *pos1;
    *pos1 = *pos2;
    *pos2 = tmp;
}
void qs_sort(int array[], long start, long end)
{
    long head = start, tail = end - 1, tmp;
    long diff = end - start;
    long pe_index;
    // якщо залишилося менше двох елементів – кінець рекурсії
    if (diff < 1)
        return;
    if (diff == 1)
        if (array[start] > array[end])
        {
            swap(&array[start], &array[end]);
            return;
        }
    // пошук індексу розділяючого елементу pe_index
    long m = (start + end) / 2;
    if (array[start] <= array[m])
    {
        if (array[m] <= array[end])
            pe_index = m;
        else if (array[end] <= array[start])
            pe_index = start;
        else
            pe_index = end;
    }
    else
    {
        if (array[start] <= array[end])
            pe_index = start;
        else if (array[end] <= array[m])
            pe_index = m;
        else
            pe_index = end;
    }
    long pe = array[pe_index]; // сам розділяючий елемент
    swap(&array[pe_index], &array[end]);


    while (1)
    {
        while (array[head] < pe)
            ++head;
        while (array[tail] > pe && tail > start)
            --tail;
        if (head >= tail)
            break;
        swap(&array[head++], &array[tail--]);
    }
    swap(&array[head], &array[end]);
    long mid = head;
    qs_sort(array, start, mid - 1); // рекурсивний виклик для 1-ої підмножини
    qs_sort(array, mid + 1, end); // рекурсивний виклик для 2-ої підмножини
}

void s_sort(int array[], int start, int end) {
    int f = 0, i, j;
    for (i = end; i >= 0; i--) {
        for (j = 0; j <= i; j++) {
            if (array[j] < array[f]) {
                f = j;
            }
        }
        swap(&array[i], &array[f]);
        f = 0;
    }
}

int are_equal(int arr1[], int arr2[], int start, int end) {
    int i;
    for (i = start; i <= end; i++) {
        if (arr1[i] != arr2[i]) {
            return 0;
        }
    }
    return 1;
}
void swap_dir(int arr[], int start, int end) {
    int i;
    for (i = start; i <= end / 2.0; i++) {
        swap(&arr[i], &arr[end - i]);
    }
}
int is_sorted(int arr[], int start, int end) {
    int i;
    for (i = start + 1; i <= end; i++) {
        if (arr[i] > arr[i - 1]) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    FILE* f1 = fopen("quick_sort.txt", "w"); fprintf(f1, "%s\n", "Before sort: ");
    FILE* f2 = fopen("choise_sort.txt", "w"); fprintf(f2, "%s\n", "Before sort: ");
    
    float quickSortTime1, quickSortTime2, choiseSortTime1, choiseSortTime2, quickDelta, choiseDelta;

    int arr1[SIZE], arr2[SIZE];
    int i, randd = 0;

    srand(time(NULL));
    for (i = 0; i < SIZE; i++)
    {
        randd = rand() % 30000;
        arr1[i] = randd;
        arr2[i] = randd;
        fprintf(f1, "%d ", randd);
        fprintf(f2, "%d ", randd);
    }


    printf("Arrays are%s equal before sorting\n\n", (arr1, arr2, 0, SIZE - 1) ? " " : " not");



    quickSortTime1 = clock() / (float)CLOCKS_PER_SEC;
    qs_sort(arr1, 0, SIZE - 1);
    quickSortTime2 = clock() / (float)CLOCKS_PER_SEC;
    swap_dir(arr1, 0, SIZE - 1);

    quickDelta = quickSortTime2 - quickSortTime1;
    printf("Array 1 is%s sorted. Quick-sort time:     %.3f seconds.\n", is_sorted(arr1, 0, SIZE - 1) ? " ": " not", quickDelta);

    choiseSortTime1 = clock() / (float)CLOCKS_PER_SEC;
    s_sort(arr2, 0, SIZE - 1);
    choiseSortTime2 = clock() / (float)CLOCKS_PER_SEC;

    choiseDelta = choiseSortTime2 - choiseSortTime1;
    printf("Array 2 is%s sorted. Selection-sort time: %.3f seconds.\n", is_sorted(arr2, 0, SIZE - 1) ? " " : " not", choiseDelta);
    
    printf("\nArrays are%s equal after sorting\n", (arr1, arr2, 0, SIZE - 1) ? " " : " not");

    fprintf(f1, "\n\n%s \n", "After sort: ");
    fprintf(f2, "\n\n%s \n", "After sort: ");


    for (i = 0; i < SIZE; i++)
    {
        fprintf(f1, "%d ", arr1[i]);
        fprintf(f2, "%d ", arr2[i]);
    }


    return 0;
}
