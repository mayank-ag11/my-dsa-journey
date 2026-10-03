#include <stdio.h>

int main() {
    char ch[10];
    int x;
    scanf("%s", ch);
    //printf("%c", ch);
    while(ch[0] != '#') {
	//scanf("%d", &x);
	//printf("%d\n", x);
	scanf("%s", ch);
	printf("%s\n", ch);
	//if(ch == '#')
	  //  break;
    }
}
