#include <stdio.h>
long long fact(int n)
{
   if(n==1) return 1;
   return (long long)n * fact(n-1);
}
int main()
{
   int n;
   scanf("%d", &n);
   long long x=fact(n);
   printf("%lld\n", x);
}
