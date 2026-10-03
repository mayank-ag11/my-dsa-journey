#include <stdio.h>

int main()
{
   int n;
   scanf("%d", &n);

   for(int i=n;i>=1;i--)
   {
     int a=n-i+1;
     for(int j=1;j<=(2*(i-1));j++)
       printf(" ");
     for(int j=i;j<=n;j++)
     {
       printf("%d", a++);
     }
     printf("\n");
   }
}
