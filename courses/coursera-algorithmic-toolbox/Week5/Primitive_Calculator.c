#include <stdio.h>

/*int GreedyCalculator(int n, int *arr)
{
  int num = 0;
  arr[0] = n;
  while(n > 1)
  {
    num++;
    if(n%3 == 0)
     n = n/3;
    else if(n%2 == 0)
     n = n/2;
    else
     n = n-1;
    arr[num] = n;
  }
  return num;
}*/

int Primitive_Calculator(int n, int *arr)
{
  int
}
int main()
{
  int n;
  scanf("%d", &n);

  int arr[n];
  int x = GreedyCalculator(n, arr);
  printf("%d\n", x);
  for(int i=x; i>=0; i--)
   printf("%d ", arr[i]);
  printf("\n");
}
