#include <stdio.h>
#include <stdlib.h>
int stack1[1000000], stack2[1000000];
int top1=-1, top2=-1;
void Push1(int x)
{
   stack1[++top1]=x;
}
void Pop1()
{
   top1--;
}

void Push2(int x)
{
   stack2[++top2]=x;
}
void Pop2()
{
   top2--;
}

int isEmpty1()
{
   return top1==-1;
}
int isEmpty2()
{
   return top2==-1;
}

int *funGame(int *arr, int n, int *out_n)
{
   (*out_n) = 0;
   int *res = (int *)malloc(sizeof(int)*(2*n));
   for(int i=n-1;i>=0;i--)
     Push1(arr[i]);
   for(int i=0;i<n;i++)
     Push2(arr[i]);

   while(!isEmpty1()&&!isEmpty2())
   {
     if(stack1[top1]==stack2[top2])
     {
       res[(*out_n)++] = 0;
       Pop1();
       Pop2();
     }
     else if(stack1[top1]>stack2[top2])
     {
       res[(*out_n)++] = 1;
       Pop2();
     }
     else
     {
       res[(*out_n)++] = 2;
       Pop1();
     }
   }
   return res;
}
int main()
{
   int n;
   scanf("%d", &n);
   int arr[n];
   for(int i=0;i<n;i++)
     scanf("%d", &arr[i]);

   int out_n;
   int *res = funGame(arr, n, &out_n);
   printf("%d", res[0]);
   for(int i=1;i<out_n;i++)
     printf(" %d", res[i]);
   printf("\n");
}
