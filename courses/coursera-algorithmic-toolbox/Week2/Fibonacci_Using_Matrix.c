#include <stdio.h>

void Multiply_for_Exponentiation(int a[2][2], int b[2][2])
{
   int mul[2][2];
   for(int i=0;i<2;i++)
     for(int j=0;j<2;j++)
       {
	 mul[i][j]=0;
	 for(int k=0;k<2;k++)
           mul[i][j]+=a[i][k]*b[k][j];
       }

   //Storing the multiplication result in a[][]
   for(int i=0;i<2;i++)
     for(int j=0;j<2;j++)
       a[i][j]=mul[i][j];
}
void Matrix_Power(int x, int A[2][2])
{
   int res[2][2]={1,0,0,1};
   while(x)
   {
     if(x%2==1)
      Multiply_for_Exponentiation(res,A);

     Multiply_for_Exponentiation(A,A);
     x=x/2;
   }
   for(int i=0;i<2;i++)
     for(int j=0;j<2;j++)
       A[i][j]=res[i][j];
}
int main()
{
   int n;
   scanf("%d", &n);

   int A[2][2]={0,1,1,1};
   Matrix_Power(n-1, A);

   int I[1][2]={0,1};
   int F[1][2]={0};

   for(int i=0;i<1;i++)
     for(int j=0;j<2;j++)
       {
	 for(int k=0;k<2;k++)
           F[i][j]+=I[i][k]*A[k][j];
       }

   printf("The %dth Fibonacci No. is : %d\n", n, F[0][1]);
}
