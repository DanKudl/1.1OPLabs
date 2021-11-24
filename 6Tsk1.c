///////////////////////////////////////main.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include "functions.h"

#define n 3
#define LENGTH 1024
#define N 3



int main() {
    double a[n], b[n], c[n], sum1[n], d[n];
    input(a, b, c, n);
    sum(a, b, sum1, n);
    sum(sum1, c, d, n);
    printf("\nResult: \n");
    for (int i = 0; i < n; i++) {
        printf("%6.2lf ", d[i]);
    }
    return 0;
}


//////////////////////////////////////////functions.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include "functions.h"


void input(double a[], double b[], double c[], int n) {
    printf("a array elements(%d): ", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &a[i]);
    }
    printf("b array elements(%d): ", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &b[i]);
    }
    printf("c array elements(%d): ", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &c[i]);
    }
}

void sum(double x[], double y[], double z[], int n) {
    for (int i = 0; i < n; i++) {
        z[i] = x[i] + y[i];
    }
}




/////////////////////////////////////////functions.h

#ifndef FUNCTIONS_H_ 
#define FUNCTIONS_H_

void input(double a[], double b[], double c[], int n);
void sum(double x[], double y[], double z[], int n);

#endif

