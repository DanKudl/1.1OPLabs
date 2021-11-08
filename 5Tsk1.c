#include <stdio.h>


double F(double x) {
    return x / (x * x + 3);
}

int F2(double y) {
    if (y < 0) return -1;
    else if (y == 0) return 0;
    else return 1;
}

void Lab5Tsk1Var21() {
    printf("y=x/(x^2 + 3)\n");

    double y = 0, a = 1.0, b = 3.0, h = 0.2;

    printf("h = "); scanf("%lf", &h);

    printf("  X     Y           X     F2  \n");

    for (double x = a; x <= b; x += h) {
        printf("%5.3lf  ", x);
        printf("%5.3lf      ", F(x));
        printf("%5.3lf  ", x);
        printf("%3d\n", F2(F(x)));
        

    }

}

int main () {
  Lab5Tsk1Var21();
  return 0;
}
