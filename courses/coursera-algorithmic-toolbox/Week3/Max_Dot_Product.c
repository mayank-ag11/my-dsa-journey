#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b)
{
   return *(long*)b > *(long*)a;
}
int main()
{
   int n;
   scanf("%d", &n);
   long A[n], B[n];

   for(int i=0;i<n;i++)
     scanf("%ld", &A[i]);
   for(int i=0;i<n;i++)
     scanf("%ld", &B[i]);

   qsort(A, n, sizeof(long), cmpfunc);
   qsort(B, n, sizeof(long), cmpfunc);

   long sum=0;
   for(int i=0;i<n;i++)
     sum+=(A[i]*B[i]);

   printf("%ld\n", sum);
}
