//To find the last digit of the Sum of Squares of Fibonacci Numbers
#include <stdio.h>

int main()
{
   long long n;
   int sum=0;
   scanf("%lld", &n);

   n=n%60; //Pisano Period of m=10

   int first=0, second=1, sqr;
   for(int i=0;i<n;i++)
   {
     sqr=(second*second)%10;
     sum=(sum+sqr)%10;
     int temp=(first+second)%10;
     first=second;
     second=temp;
   }
   printf("%d\n", sum);
}
