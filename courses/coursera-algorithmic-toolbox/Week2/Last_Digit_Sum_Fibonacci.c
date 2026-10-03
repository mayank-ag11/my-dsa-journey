//C Program to find the last digit of the Sum of Fibonacci Numbers
#include <stdio.h>

int main()
{
   long long n;
   int sum=0;
   scanf("%lld", &n);

   n=n%60; //Pisano Period for m=10
   int first=0, second=1;
   for(int i=0;i<n;i++)
   {
     sum=(sum+second)%10;
     int temp=(first+second)%10;
     first=second;
     second=temp;
   }
   printf("%d\n", sum);
}
