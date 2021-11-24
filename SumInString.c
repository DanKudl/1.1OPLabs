#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include "functions.h"

//#define n 3
#define LENGTH 1024


int main() {
    char str[LENGTH];
    gets(str);

    int sum = 0, x;
    char num[256]; int j = 0;

    int writing = 0;//bool

    int l = strlen(str);

    for (int i = 0; i < l; i++) {

        if (__isascii(str[i])) {
            if (str[i] == '=') {
                writing = 1;
            }
            if (str[i] == ' ') {
                writing = 0;
                j = 0;

                x = atoi(num);
                sum += x;
                for (int xd = 0; xd < 256; xd++) {
                    num[xd] = ' ';
                }
                printf("%d + ", x);
            }

            if (isdigit(str[i])) {
                num[j] = str[i];
                j++;
            }
        }
    }

    x = atoi(num);
    sum += x;
   
    printf("%d = ", x);

    printf("%d", sum);

    return 0;
}
