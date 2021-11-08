#include <stdio.h>
#include <math.h>
int main() {
double h = 0.05, eps = 0.005, A=-0.9, B=0.9;

   // printf("Vvedit promijok A,B: "); scanf("%lf %lf", &A, &B);
    // printf("Vvedit eps: "); scanf("%lf", &eps);

    for (double x = A; x <= B; x += h) {
        printf("x = ");
        if (x >= 0) printf(" %.3lf", x);
        else printf("%.3lf", x);
        

        double Si = 24 * x;
        int i = 2;
        double sum = Si;
        while (fabs(Si) >= eps) {
            Si = -Si * x * (i + 3) / i;
            sum += Si;
            i++;
        }


        double dob = (1.0 / 6.0) * sum;
        double s = 1.0 - dob;
        

        double y = pow((1 + x), -4);
        
        printf(" \ty = % 11.5lf\t", y/10.0);
        
       
        printf(" s = % 11.5lf\n", s / 10.0);
}
