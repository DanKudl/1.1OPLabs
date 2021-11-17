
/////////////////////////////////////////////////////////main.c
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include "functions.h"


int main() {

    double a, b, h;
    printf("a, b: ");
    scanf("%lf %lf", &a, &b);

    printf("h: ");
    scanf("%lf", &h);

    tab1(a, b, h);
    tab2(a, b, h);

    return 0;
}


///////////////////////////////////////////////////////////////////functions.c
#include <stdio.h>
#include <math.h>
#include "functions.h"

double f(double x) {
	return x / (x * x + 3);
}
double y(double x, double* ptr) {
	*ptr = f(x);
	if (*ptr > 0)
		return 1;
	if (*ptr < 0)
		return -1;
	return 0;

}
void tab1(double a, double b, double h) {
	printf("\n X\t\t First method\n");
	while (a <= b || fabs(b - a) < 1E-14)
	{
		printf("% .7lf\t% .7lf\n", a, f(a));
		a += h;
	}
}

void tab2(double a, double b, double h) {
	printf("\n X\t\t First method\t Second method\n \n");
	while (a <= b || fabs(b - a) < 1E-14)
	{
		double F, Y = y(a, &F);
		printf("% .7lf\t% .7lf\t% .7lf\n", a, F, Y);
		a += h;
	}
}


////////////////////////////////////////////////////////functions.h

#ifndef FUNCTIONS_H_   /* Include guard */
#define FUNCTIONS_H_

double f(double);
double y(double, double*);
void tab1(double, double, double);
void tab2(double, double, double);

#endif // FOO_H_
