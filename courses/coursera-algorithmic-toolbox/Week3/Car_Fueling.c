#include <stdio.h>

int Min_Refills(int arr[], int n, int M)
{
   int numRefills=0, currRefill=0, lastRefill;

   while(currRefill<=n)
   {
     lastRefill = currRefill;
     while(currRefill<=n && (arr[currRefill+1] - arr[lastRefill])<=M)
       currRefill++;

     if(currRefill==lastRefill)
      return -1;
     if(currRefill<=n)
      numRefills++;
   }
   return numRefills;
}
int main()
{
   int D, M, n;
   scanf("%d %d %d", &D, &M, &n);
   int arr[n+2];

   //this arr represents the whole pathway 0 as starting point A and D as B
   arr[0] = 0;
   for(int i=1;i<=n;i++)
     scanf("%d", &arr[i]);
   arr[n+1] = D;

   int res = Min_Refills(arr,n,M);
   printf("%d\n", res);
}
