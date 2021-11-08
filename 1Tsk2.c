#include <stdio.h>
int main () {
  //Визначає номер мінімального числа та середнє значення всіх більших за –10 введених з
    //клавіатури від‟ємних чисел. (Кількість чисел 10).
    double n1, n2, n3, n4, n5, n6, n7, n8, n9, n10;
    scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf %lf", &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8, &n9, &n10);

    
    double smallest; int index=1;
    if (n1 < n2) {
        smallest = n1;
        index = 1;
    }
    else {  
        smallest = n2;
        index = 2;
    }
    
    if (n3 < smallest) {
        smallest = n3;
        index = 3;
    }
    if (n4 < smallest) {
        smallest = n4;
        index = 4;
    }
    if (n5 < smallest) {
        smallest = n5;
        index = 5;
    }
    if (n6 < smallest) {
        smallest = n6;
        index = 6;
    }
    if (n7 < smallest) {
        smallest = n7;
        index = 7;
    }
    if (n8 < smallest) {
        smallest = n8;
        index = 8;
    }
    if (n9 < smallest) {
        smallest = n9;
        index = 9;
    }
    if (n10 < smallest) {
        smallest = n10;
        index = 10;
    }

    //calculating avarage
    double sum = 0, num = 0;

    if (-10 < n1 && n1 < 0) {
        sum += n1;
        num++;
    }
    if (-10 < n2 && n2 < 0) {
        sum += n2;
        num++;
    }
    if (-10 < n3 && n3 < 0) {
        sum += n3;
        num++;
    }
    if (-10 < n4 && n4 < 0) {
        sum += n4;
        num++;
    }
    if (-10 < n5 && n5 < 0) {
        sum += n5;
        num++;
    }
    if (-10 < n6 && n6 < 0) {
        sum += n6;
        num++;
    }
    if (-10 < n7 && n7 < 0) {
        sum += n7;
        num++;
    }
    if (-10 < n8 && n8 < 0) {
        sum += n8;
        num++;
    }
    if (-10 < n9 && n9 < 0) {
        sum += n9;
        num++;
    }
    if (-10 < n10 && n10 < 0) {
        sum += n10;
        num++;
    }

    //output
    printf("\nIndex of smallest number: %d, number is: %lf\n", index, smallest);
    double avarage = sum / num;
    printf("Avarage: %lf\n", avarage); 
}
