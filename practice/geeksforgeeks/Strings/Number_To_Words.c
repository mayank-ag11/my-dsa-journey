#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *numToWords(int n, char *s)
{
    char *one[]={"", "one ", "two ","three ", "four ","five ","six ", "seven ", "eight ", "nine ", "ten ","eleven ","twelve ", "thirteen ", "fourteen ", "fifteen ", "sixteen ", "seventeen ", "eighteen ", "nineteen "};
    char *ten[]={" ", " ","twenty ", "thirty ", "forty ", "fifty ", "sixty ", "seventy ", "eighty ", "ninety "};
    char *str=(char*) malloc (sizeof(char)*50);
    if(n>19)
    {
       strcat(str,ten[n/10]);
       strcat(str,one[n%10]);
    }
    else
       strcat(str, one[n]);
    if(n)
       strcat(str,s);
    return str;
}
void intToWords(int n)
{
    char out[100]={""};
    if(n==0)
    {
      printf("zero");
      return;
    }
    //strcat(out, numToWords(((n/100000)%100), "lakhs "));
    strcat(out, numToWords(((n/1000)%100), "thousand "));
    strcat(out, numToWords(((n/100)%10), "hundred "));

    if(n>100&&n%100)
      strcat(out, "and ");

    strcat(out, numToWords((n%100), ""));
    out[strlen(out)-1]='\0';
    printf("%s", out);
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--)
	{
	    int n;
	    scanf("%d", &n);
	    intToWords(n);
	    printf("\n");
	}
	return 0;
}
