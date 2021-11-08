#include <stdio.h>
int main () {
 int choise;
    printf("1 - indexi, 2 - vkazivniki: ");
    scanf("%d", &choise);

    printf("N = %d\n", N);

    if (choise == 1) {
        //indexi
        double arr[N];
        for (int i = 0; i < N; i++) {
            scanf("%lf", &arr[i]);
        }

        double sum = 0, arifm; int max_index = 0;

        for (int i = 0; i < N; i++) {
            sum += arr[i];
            if (arr[i] > arr[max_index]) {
                max_index = i;
            }
        }

        arifm = sum / N;

        printf("Ser arifm = %lf\n", arifm);

        for (int i = max_index + 1; i < N; i++) {
            arr[i] += arifm;
        }

        for (int i = 0; i < N; i++) {
            printf("%.2lf ", arr[i]);
        }

        
    }
    else if(choise == 2) {
        //vkazivniki
        double arr[N];
        for (int i = 0; i < N; i++) {
            scanf("%lf", arr + i);
        }

        double sum = 0, arifm; int max_index = 0;

        for (int i = 0; i < N; i++) {
            sum += *(arr + i);
            if (*(arr + i) > *(arr + max_index)) {
                max_index = i;
            }
        }

        arifm = sum / N;

        printf("Ser arifm = %lf\n", arifm);

        for (int i = max_index + 1; i < N; i++) {
            *(arr + i) += arifm;
        }

        for (int i = 0; i < N; i++) {
            printf("%.2lf ", *(arr + i));
        }
    } 
}
