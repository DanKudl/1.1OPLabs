#include <stdio.h>
int main() {
    double x = 1.825, y = 18.225;
    double a; a = fabs(pow(x, y / x) - cbrt(y / x));
    printf("a = %lf", a);
    return 0;
}
