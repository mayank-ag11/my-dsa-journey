#include <stdio.h>

int Majority_Check(int *arr, int l, int r, int a, int b)
{
  if(a==-1&&b==-1)
   return -1;

  int n = (r-l+1)/2;
  int ctr_a = 0, ctr_b = 0;
  while(l<=r)
  {
    if(arr[l]==a) ctr_a++;
    else if(arr[l]==b) ctr_b++;
    l++;
  }

  if(ctr_a>n) return a;
  else if(ctr_b>n) return b;
  return -1;
}
int Majority_Element(int *arr, int l, int r)
{
  if(l == r)
   return arr[l];

  int mid = l + (r - l)/2;
  int a = Majority_Element(arr, l, mid);
  int b = Majority_Element(arr, mid+1, r);

  return Majority_Check(arr, l, r, a, b);
}
int main()
{
  int n;
  scanf("%d", &n);
  int arr[n];
  for(int i=0;i<n;i++)
    scanf("%d", &arr[i]);

  int res = Majority_Element(arr, 0, n-1);
  printf("%d\n", res!=-1);
}
