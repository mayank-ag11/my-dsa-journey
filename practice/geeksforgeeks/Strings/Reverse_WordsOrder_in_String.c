#include <stdio.h>
#include <string.h>
/*Algorithm :
  First of all, reverse the individual words
  Then, reverse the whole string to get desired output */
void revWordsString(char *str)
{
   int i=0,p=0,n=strlen(str);
   for(i=0;i<=n;i++)
   {
     if(str[i]=='.'||str[i]=='\0')
     {
       int l=p,r=i-1;
       while(l<=r)
       {
         char temp=str[l];
         str[l]=str[r];
         str[r]=temp;
         l++;
         r--;
       }
       
       p=i+1;
     }
   }
}
void revWordsOrder(char *str)
{
   revWordsString(str);
   int i=0,j,temp;
   j=strlen(str)-1;
   while(i<=j)
   {
     temp=str[i];
     str[i]=str[j];
     str[j]=temp;
     i++;
     j--;
   }
}
int main() {
	int t;
	scanf("%d", &t);
	while(t--)
	{
	    char s[2000];
	    scanf("%s", s);
	    
	    revWordsOrder(s);
	    printf("%s\n", s);
	    
	}
	return 0;
}
