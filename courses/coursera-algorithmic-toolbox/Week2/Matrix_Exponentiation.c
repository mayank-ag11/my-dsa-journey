#include <stdio.h>

void Multiply(int n, int a[n][n], int b[n][n])
{
   int mul[n][n];
   for(int i=0;i<n;i++)
     for(int j=0;j<n;j++)
       {
	 mul[i][j]=0;
	 for(int k=0;k<n;k++)
           mul[i][j]+=a[i][k]*b[k][j];
       }

   //Storing the multiplication result in a[][]
   for(int i=0;i<n;i++)
     for(int j=0;j<n;j++)
       a[i][j]=mul[i][j];
}

int main()
{
   int n=2,i,j,k;
   printf("Enter the order of the matrix A : ");
   scanf("%d", &n);

   int A[n][n];
   int res[n][n];

   //Initializing res as Identity matrix
   for(i=0;i<n;i++)
     for(j=0;j<n;j++)
     {
       if(i==j)
	res[i][j]=1;
       else res[i][j]=0;
     }

   printf("Enter the elements of matrix A : ");
   for(i=0;i<n;i++)
    for(j=0;j<n;j++)
      scanf("%d", &A[i][j]);

   int x;
   printf("Enter the power : ");
   scanf("%d", &x);

   while(x)
   {
     if(x%2==1)
      {
	Multiply(n,res,A);
      }
     Multiply(n,A,A);
     x=x/2;
   }

   //Printing the final result
   printf("The resultant matrix A^x :\n");
   for(i=0;i<n;i++)
     {
	for(j=0;j<n;j++)
          printf("%d ", res[i][j]);
	printf("\n");
     }
}
