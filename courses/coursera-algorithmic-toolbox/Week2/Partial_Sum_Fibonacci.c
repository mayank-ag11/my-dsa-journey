//To find the last digit of the Sum of Fibonacci Numbers (Fm to Fn)
#include <stdio.h>

int main()
{
   long long n,m;
   int sum=0;
   scanf("%lld %lld", &m, &n);

   n=n%60; //Pisano Period of m=10
   m=m%60;

   if(m>n)
    n=n+60;
   int first=0, second=1;
   for(int i=0;i<n;i++)
   {
     if(i>=m-1)
       sum=(sum+second)%10;
     int temp=(first+second)%10;
     first=second;
     second=temp;
   }
   printf("%d\n", sum);
}
