#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define POW2(x) ((x) * (x))
#define POW3(x) ((x) * (x) * (x))
#define MAX2(x, y) (((x) > (y)) ? (x) : (y))
#define MIN2(x, y) (((x) < (y)) ? (x) : (y))
#define MOD(x) ((x) < (0)) ? ((-1) * (x)) : (x)

#define LINE 1

#if LINE == 1
#define RES(x, y, z) (MAX2(POW3(x), POW2(x + y)) * MIN2(x - y, y - z))
#else
#define RES(x, y, z) (MIN2(MOD(x - z), MOD(x + z)))
#endif

int main(void) {
	double x, y, z, w = 0;

	printf("Enter x: "); scanf("%lf", &x);
	printf("Enter y: "); scanf("%lf", &y);
	printf("Enter z: "); scanf("%lf", &z);

	w = RES(x, y, z);

	printf("w = %lf\n", w);
	return 0;
}
