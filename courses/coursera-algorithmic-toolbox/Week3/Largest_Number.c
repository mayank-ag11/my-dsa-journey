#include <stdio.h>

long Largest_Number(int *arr, int n)
{
  long ans;

}
int main()
{
  int n;
  scanf("%d", &n);
  int arr[n];
  for(int i=0;i<n;i++)
    scanf("%d", &arr[i]);

  long L = Largest_Number(arr, n);
  printf("%ld\n", L);
}
