#include <stdio.h>
int main() {
 //З клавіатури ввести границі числового проміжку. Знайти і надрукувати всі парні числа з
    //цього проміжку, які не містять цифри 7. Знайти їх кількість або вивести повідомлення про
    //їх відсутність.

    long int a, b;
    scanf("%ld %ld", &a, &b);


    long int EvenNumbers = 0;

    for (long int num = a; num <= b; num++) {
        if (num % 2 == 0) {
            int consistSeven = 0; long int n = num;
            while (n > 9) {
                if (n % 10 == 7) {
                    consistSeven = 1;
                }
                n /= 10;
            }
            if (n != 7 && consistSeven == 0) {
                EvenNumbers++;
                if (EvenNumbers == 1) {
                    printf("Even numbers without 7:\n");
                }
                printf("%ld ", num);
            }
        }
    }

    if (EvenNumbers == 0) {
        printf("There is no even numbers without 7\n");
    }
    else {
        printf("\nTotal numbers: %ld", EvenNumbers);
    } 
}
