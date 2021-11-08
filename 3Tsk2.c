#include <stdio.h>
int main () {
  int choise;
    printf("1 - indexi, 2 - vkazivniki: ");
    scanf("%d", &choise);

    printf("X[5][7]:\n");

    int X[N][M];

    int max_i = 0, max_j = 0, min_i = 0, min_j = 0;

    if (choise == 1) {

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf("%d", &X[i][j]);
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (X[i][j] > X[max_i][max_j]) {
                    max_i = i;
                    max_j = j;
                }
                if (X[i][j] < X[min_i][min_j]) {
                    min_i = i;
                    min_j = j;
                }
            }
        }

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                printf("%d\t ", X[i][j]);
            }
            printf("\n");
        }



        int Sk_dob = 0;

        for (int i = 0; i < N; i++) {
            Sk_dob += X[max_i][i] * X[i][min_j];
        }

        

        printf("Skalyarnii dobutok = %d", Sk_dob);

    }
    else {

       
        for (int i = 0; i < N * M; i++)
        {
            scanf("%d", *X + i);
        }

       
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (*(X + i*j) > *(X + max_i*max_j)) {
                    max_i = i;
                    max_j = j;
                }
                if (*(X + i*j) < *(X + min_i*min_j)) {
                    min_i = i;
                    min_j = j;
                }
            }
        }
        

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                printf("%d\t ", X[i][j]);
            }
            printf("\n");
        }


        int Sk_dob = 0;
        int d1 = 0, d2 = 0;


        for (int i = 0; i < N; i++) {
            d1 = *(*X + M * i);
            d2 = *(*X + max_i * M + i);
            

            Sk_dob += d1 * d2;
        }


        

        printf("Skalyarnii dobutok = %d", Sk_dob);

    }
}
