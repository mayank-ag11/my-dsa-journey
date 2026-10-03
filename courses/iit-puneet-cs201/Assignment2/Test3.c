#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*int isdigit(char ch) {
    if (ch >= '0' && ch <= '9')
       return 1;
    return 0;
}*/
int isNumeric(char* str) {
    for(int i=0; i<strlen(str); i++) {
	    printf("Working");
	if(isdigit(str[i]) == 0)
	    return 0;
    }
    return 1;
}

int main() {
    char str[10] = "111+";

   // printf("%d\n", isdigit('1'));
    //printf("%d\n", isdigit('+'));
   // int x = atoi(str);
   if(isNumeric(str))
	printf("It's a Number");
   //printf("%d\n", x);
}
