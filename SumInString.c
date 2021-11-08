#include <stdio.h>
int main () {
 char str[LENGTH];
    gets(str);


    int sum = 0;
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

                int x = atoi(num);
                sum += x;
            }

            if (isdigit(str[i])) {
                num[j] = str[i];
                j++;
                if (__isascii(str[i + 2]) == 0) {
                    int x = atoi(num);
                    sum += x;
                }
            }


        }
        else {
            break;
        }
    }
    printf("%d", sum);
 
}
