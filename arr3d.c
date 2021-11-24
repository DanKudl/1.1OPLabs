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





int arr3d() {
    int arr3d[N + 2][N][N];
    int rez[N][N];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                scanf("%d", &arr3d[i][j][k]);
            }
        }
    }
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            arr3d[N + 1][j][k] = arr3d[0][j][k];
        }
    }
    int sum = 0, s = 0;
    int dob = 1;
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            for (int I = 0; I < N; I++) {
                sum += arr3d[I][j][k];
            }
            arr3d[N][j][k] = sum;
            sum = 0;
        }
    }

    for (int I = 1; I < N; I++) {
        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                for (int xd = 0; xd < N; xd++) {
                    s += arr3d[N + 1][j][xd] * arr3d[I][xd][k];
                }
                rez[k][j] = s;
                s = 0;
            }
        }

        for (int j = 0; j < N; j++) {
            for (int k = 0; k < N; k++) {
                arr3d[N + 1][k][j] = rez[k][j];
                rez[k][j] = 0;
            }
        }
    }
    printf("\n\narr3d[N]: \n");
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            printf("%5d ", arr3d[N][j][k]);
        }
        printf("\n");
    }
    printf("\n\narr3d[N+1]: \n");
    for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
            printf("%5d ", arr3d[N+1][j][k]);
        }
        printf("\n");
    }
    return 0;
}
