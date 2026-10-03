#include <stdio.h>
int Pisano_Period(int m)
{
   int prev=0, curr=1;
   for(int i=0;i<(m*m);i++)
   {
     int temp=prev;
     prev=curr;
     curr=(temp+curr)%m;

     if(prev==0&&curr==1)
      return i+1;
   }
}
int main()
{
   long long n;
   int m;
   scanf("%lld %d", &n, &m);

   if(n>m)
    {
      int pp=Pisano_Period(m);
      n=n%pp;
    }
   int first=0, second=1, res=n%m;
   for(int i=1;i<n;i++)
    {
      res=(first+second)%m;
      first=second;
      second=res;
    }
   printf("%d\n", res);
}
