#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int max_search(int* arr, int arrSize, int currPos)
{
    if (currPos >= arrSize)
        return 0;

    int temp = max_search(arr, arrSize, currPos + 1);

    if (arr[temp] > arr[currPos]) return temp;
    else return currPos;
}



int main()
{
    int n, max;
    printf("Amount of numbers: "); scanf("%d", &n);
    int* arr = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) scanf("%d", arr + i);
    max = arr[max_search(arr, n, 0)];
    printf("Max num of array: %d\n", max);
    return 0;
}
