#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include "functions.h"

#define n 3

void input(double a[], double b[], double c[]) {
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

void sum(double x[], double y[], double z[]) {
    for (int i = 0; i < n; i++) {
        z[i] = x[i] + y[i];
    }
}

int main() {
    double a[n], b[n], c[n], sum1[n], d[n];
    input(a, b, c);
    sum(a, b, sum1);
    sum(sum1, c, d);
    printf("Result:              ");
    for (int i = 0; i < n; i++) {
        printf("%6.2lf ", d[i]);
    }
    return 0;
}
