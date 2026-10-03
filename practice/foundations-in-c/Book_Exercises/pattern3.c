#include <stdio.h>

int main()
{
   int n,i,j;
   scanf("%d", &n);

   for(i=1;i<=n/2;i++)
   {
      for(j=1;j<i;j++)
	printf(" ");

      for(j=0;j<i;j++)
	printf("#");

      for(j=i*4;j<n*2;j++)
	printf(" ");

      for(j=0;j<i;j++)
        printf("#");

      printf("\n");
   }

   for(i=n/2;i>=1;i--)
   {
      for(j=i;j>1;j--)
	printf(" ");

      for(j=i;j>0;j--)
	printf("#");

      for(j=n*2;j>i*4;j--)
	printf(" ");

      for(j=i;j>0;j--)
	printf("#");

      printf("\n");
   }
}
