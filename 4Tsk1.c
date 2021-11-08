#include <stdio.h>
int main () {
   char consonants[] = "bcdfghjklmnpqrstvwxz"; int cons = 20;
    char str[LENGTH];
    
    gets(str);
    
    int len = strlen(str), count = 0;
    int space_needed = 0;

    for (int i = 0; i < len; i++) {
        space_needed = 1;
        if (str[i] != '.' && str[i] != ' ') {
            for (int j = 0; j < cons; j++) {
                if (tolower(str[i]) == consonants[j]) {
                    printf("%c", str[i]);
                    count++;
                    space_needed = 0;
                    j = cons; //переробити в вайл
                }
            }
        }
        else {
            i = LENGTH;
        }
        if(space_needed)
        printf(" ");
    }

    printf("\n\nConsonants: %d", count); 
}
