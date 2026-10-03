#include <stdio.h>

int main()
{
   int n;
   scanf("%d", &n);

   for(int i=1;i<=n/2;i++)
   {
      for(int j=i;j<n/2;j++)
	printf(" ");

      for(int k=1;k<=i*2;k++)
	printf("#");

      printf("\n");
   }
   
   for(int i=0;i<n/2;i++)
   {
      for(int j=0;j<i;j++)
	printf(" ");

      for(int k=i*2;k<n;k++)
        printf("#");

      printf("\n");
   }
}
