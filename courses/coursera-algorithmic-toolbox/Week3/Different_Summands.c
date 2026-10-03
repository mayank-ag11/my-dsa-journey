#include <stdio.h>
#include <stdlib.h>

int Distribution(int *arr, int n)
{
  int i = 0;
  int num = 1;

  while(1)
  {
    if(num==n)
    {
      break;
    }
    else if((num>=n-num))
    {
      num++;
      continue;
    }
    arr[i++] = num;
    n = n - num;
    num++;
  }
  arr[i++] = num;
  return i;
}
int main()
{
  int n;
  scanf("%d", &n);

  if(n==0)
   printf("0\n");
  else
  {
    int arr[n/2];
    n = Distribution(arr, n);
  
    printf("%d\n%d", n, arr[0]);
    for(int i=1;i<n;i++)
      printf(" %d", arr[i]);
    printf("\n");
  }
}
