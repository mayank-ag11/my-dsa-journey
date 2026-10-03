#include <stdio.h>

int a=0;
void Merge(int *arr, int l, int mid, int r)
{
  int i,j,k;
  int n1 = mid - l + 1;
  int n2 = r - mid;

  int L[n1], R[n2];

  //Copy data to temp arrays
  for(i=0;i<n1;i++)
    L[i] = arr[l + i];
  for(j=0;j<n2;j++)
    R[j] = arr[mid + 1 + j];

  //Merge the temp arrays back into arr[l..r]
  i = j = 0;
  k = l;

  while(i<n1 && j<n2)
  {
    if(L[i] <= R[j])
      arr[k++] = L[i++];
    else
    {
      a += n1 - i;
      arr[k++] = R[j++];
    }
  }

  while(i<n1)
    arr[k++] = L[i++];

  while(j<n2)
    arr[k++] = R[j++];
  //return a;
}

int MergeSort(int *arr, int l, int r)
{
  //static int a = 0;
  if(l==r)
   return a;

  int mid = l + (r - l)/2;
  MergeSort(arr, l, mid);
  MergeSort(arr, mid+1, r);

  Merge(arr, l, mid, r);
  return a;
}

int main()
{
  int n;
  scanf("%d", &n);
  int arr[n];
  for(int i=0;i<n;i++)
    scanf("%d", &arr[i]);

  int res = MergeSort(arr, 0, n-1);
  printf("%d\n", res);
}
