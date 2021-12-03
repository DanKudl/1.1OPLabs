
//lab 7.2 main.c
#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include "functions.h"
#include <conio.h>
#include <stdarg.h>

#define n 3
#define LENGTH 1024
#define N 3


void(*ptr)(double a, double b, double h);

int main() {
    double a = 0, b = M_PI;
    double h;
    printf("h: "); scanf("%lf", &h);
    int choise = -1;
    printf("Type of tabulation\n1-for 2-while 3-do while: "); scanf("%d", &choise);
    if(choise == 1) ptr = tab_for;
    else if(choise == 2) ptr = tab_while;
    else ptr = tab_do;

    ptr(a, b, h);
    return 0;
}


////////////////////functions.c

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include "functions.h"

double f(double x) {
    double c = cos(x);
    return (x * sin(x)) / (1 + c * c);
}
void tab_for(double a, double b, double h) {
    printf("for loop tabulation:\n");
    for (a; a <= b; a += h) {
        printf("%8lf %8lf\n", a, f(a));
    }
}
void tab_while(double a, double b, double h) {
    printf("\n\nwhile loop tabulation:\n");
    while (a <= b) {
        printf("%8lf %8lf\n", a, f(a));
        a += h;
    }
}
void tab_do(double a, double b, double h) {
    printf("\n\ndo_while loop tabulation:\n");
    do {
        printf("%8lf %8lf\n", a, f(a));
        a += h;
    } while (a <= b);
}

////////////////functions.h

#ifndef FUNCTIONS_H_ 
#define FUNCTIONS_H_

double f(double x);
void tab_for(double a, double b, double h);
void tab_while(double a, double b, double h);
void tab_do(double a, double b, double h);

#endif
