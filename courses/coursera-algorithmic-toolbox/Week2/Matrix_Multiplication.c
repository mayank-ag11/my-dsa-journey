#include <stdio.h>

int main()
{
   int r1,r2,c1,c2,i,j,k;
   printf("Enter the row and column of matrix A : ");
   scanf("%d %d", &r1, &c1);
   printf("Enter the row and column of matrix B : ");
   scanf("%d %d", &r2, &c2);
   int a[r1][c1], b[r2][c2],c[r1][c2];
   if(r2!=c1)
    {
      printf("Can't Multiply");
      return 0;
    }
   printf("Enter the elements of matrix A : ");
   for(i=0;i<r1;i++)
     for(j=0;j<c1;j++)
       scanf("%d", &a[i][j]);

   printf("Enter the elements of matrix B : ");
   for(i=0;i<r2;i++)
     for(j=0;j<c2;j++)
       scanf("%d", &b[i][j]);

   for(i=0;i<r1;i++)
     for(j=0;j<c2;j++)
       {
	 c[i][j]=0;
	 for(k=0;k<c1;k++)
           c[i][j]+=a[i][k]*b[k][j];
       }

   printf("\nThe resultant matrix is :\n");
   for(i=0;i<r1;i++)
     {
       for(j=0;j<c2;j++)
	 printf("%d ", c[i][j]);
       printf("\n");
     }
}
