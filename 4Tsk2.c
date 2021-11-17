#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <stdlib.h>
#include "functions.h"

//#define a 1.0
//#define b 3.0



int main()
{
    FILE* input_file;
    FILE* output_file;
    FILE* log_file = fopen("log.log", "a");
    double x, y, a;
    time_t time1, time2 = 0, time3 = 0, time4 = 0, time5 = 0;
    time(&time1);
    char* log_print = ctime(&time1);
    log_print[strlen(log_print) - 1] = '\0';
    fprintf(log_file, "[%s] Program started\n", log_print);
    char file_name[50]; char output_name[50];
    char choise = ' ';
    printf("Enter the input file name: ");
    scanf("%s", file_name);
    printf("Bin or Txt file: ");
    while (!isalpha(choise)) {
        scanf("%c", &choise);
    }



    if (choise == 'b') {
        strcat(file_name, ".bin");
        input_file = fopen(file_name, "rb");
        if (input_file == NULL) {
            printf("Cant open the input file, write x and y parameters: ");
            scanf("%lf %lf", &x, &y);
            a = fabs(pow(x, y / x) - cbrt(y / x));
            input_file = fopen(file_name, "wb");
            fprintf(input_file, "%lf %lf", x, y);
            printf("a = %lf, x(%lf) and y(%lf) writed to %s file\n", a, x, y, file_name);
            fclose(input_file);

            time(&time2);
            log_print = ctime(&time2);
            log_print[strlen(log_print) - 1] = '\0';
            fprintf(log_file, "[%s] Parameters writed to file\n", log_print);

            time(&time3);
            log_print = ctime(&time3);
            log_print[strlen(log_print) - 1] = '\0';
            fprintf(log_file, "[%s] Program ended\n\n", log_print);
            fclose(input_file);
            fclose(log_file);

            return 0;
        }
        else {
            char line[30];
            int len = fread(line, sizeof(char), 25, input_file);
            char* ptr;
            char* str = strtok(line, " ");
            x = strtod(str, &ptr);
            str = strtok(NULL, " ");
            y = strtod(str, &ptr);
            printf("values x = %lf y = %lf readed\n", x, y);

            time(&time2);
            log_print = ctime(&time2);
            log_print[strlen(log_print) - 1] = '\0';
            fprintf(log_file, "[%s] Parameters file \"%s\" opened. x = %lf, y = %lf\n", log_print, file_name, x, y);
        }
    }
    else {
        strcat(file_name, ".txt");
        input_file = fopen(file_name, "r");
        if (input_file == NULL) {
            printf("Cant open the input file, write x and y parameters: ");
            scanf("%lf %lf", &x, &y);
            a = fabs(pow(x, y / x) - cbrt(y / x));
            input_file = fopen(file_name, "w");
            fprintf(input_file, "%lf %lf", x, y);
            printf("a = %lf, x(%lf) and y(%lf) writed to %s file\n", a, x, y, file_name);
            fclose(input_file);
            return 0;
        }
        else {
            fscanf(input_file, "%lf", &x);
            fscanf(input_file, "%lf", &y);
            printf("values x = %lf y = %lf readed\n", x, y);

            time(&time2);
            log_print = ctime(&time2);
            log_print[strlen(log_print) - 1] = '\0';
            fprintf(log_file, "[%s] Parameters file \"%s\" opened. x = %lf, y = %lf\n", log_print, file_name, x, y);
        }
    }

    a = fabs(pow(x, y / x) - cbrt(y / x));
    time(&time3);
    log_print = ctime(&time3);
    log_print[strlen(log_print) - 1] = '\0';
    fprintf(log_file, "[%s] Expression calculated. Result = %lf\n", log_print, a);

    choise = ' ';
    printf("Enter the output file name: ");
    scanf("%s", &output_name);
    printf("Bin or Txt file: ");
    while (!isalpha(choise)) {
        scanf("%c", &choise);
    }

    if (choise == 'b') {
        strcat(output_name, ".bin");
        output_file = fopen(output_name, "wb");
        fprintf(output_file, "%lf", a);

        time(&time4);
        log_print = ctime(&time4);
        log_print[strlen(log_print) - 1] = '\0';
        fprintf(log_file, "[%s] Output file \"%s\" saved\n", log_print, output_name);
    }
    else {
        strcat(output_name, ".txt");
        output_file = fopen(output_name, "w");
        fprintf(output_file, "%lf", a);

        time(&time4);
        log_print = ctime(&time4);
        log_print[strlen(log_print) - 1] = '\0';
        fprintf(log_file, "[%s] Output file \"%s\" saved\n", log_print, output_name);
    }

    time(&time5);
    log_print = ctime(&time5);
    log_print[strlen(log_print) - 1] = '\0';
    fprintf(log_file, "[%s] Program ended\n\n", log_print);
    fclose(input_file);
    fclose(log_file);
    return 0;
}

