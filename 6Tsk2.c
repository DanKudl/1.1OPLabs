

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




int is_sequence(int num, ...)
{
    int term, prev;
    va_list arg_list;
    va_start(arg_list, num);

    prev = num;
    term = va_arg(arg_list, int);

    if (term <= prev) {
        return 0;
    }
    prev = term;

    while ((term = va_arg(arg_list, int)) != -1)
    {
        if (term <= prev) {
            return 0;
        }
        prev = term;
    }
    va_end(arg_list);
    return 1;
}

int main() {
    int l = is_sequence(-7, -6,-5,-4,-3, -1);
    printf("%d", l);
}

