#include <stdio.h>

int BinarySearch(int *arr, int l, int r, int key)
{
  if(r < l)
   return -1;

  int mid = l + (r - l)/2;

  if(key == arr[mid])
   return mid;
  else if(key < arr[mid])
   return BinarySearch(arr, l, mid-1, key);
  else
   return BinarySearch(arr, mid+1, r, key);
}
int main()
{
  int n;
  scanf("%d", &n);
  
  int arr[n];
  for(int i=0;i<n;i++)
    scanf("%d", &arr[i]);

  int k, x;
  scanf("%d", &k);
  scanf("%d", &x);

  x = BinarySearch(arr, 0, n-1, x);
  printf("%d", x);
  for(int i=1;i<k;i++)
  {
    int x;
    scanf("%d", &x);

    x = BinarySearch(arr, 0, n-1, x);
    printf(" %d", x);
  }
  printf("\n");
}
