#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

/*int partition2(int *a, int l, int r)
{
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a, i, j);
    }
  }
  swap(a, l, j);
  return j;
}*/

int partition3(int *arr, int l, int r, int *m1)
{
  int s = -1, e = r+1;
  int i = 0;
  int x = arr[l];
  while(i<r+1 && i<e)
  {
    if(arr[i]<x)
    {
      s++;
      swap(&arr[i], &arr[s]);
      if(i==s) i++;
    }
    else if(arr[i]>x)
    {
      e--;
      swap(&arr[i], &arr[e]);
    }
    else
      i++;
  }
  *m1 = s+1;
  return e-1;
}

void Randomized_QuickSort(int *arr, int l, int r)
{
  if(l>=r)
   return;
  int k = l + rand() % (r-l+1);
  swap(&arr[l], &arr[k]);
  int m1,m2;
  m2 = partition3(arr, l, r, &m1);
  Randomized_QuickSort(arr, l, m1-1);
  Randomized_QuickSort(arr, m2+1, r);
}
int main()
{
  //clock_t begin = clock();
  int n = 100000;
  scanf("%d", &n);
  int arr[n];
  for(int i=0;i<n;i++)
    scanf("%d", &arr[i]);

  Randomized_QuickSort(arr, 0, n-1);
  printf("%d", arr[0]);
  for(int i=1;i<n;i++)
    printf(" %d", arr[i]);
  printf("\n");
  //clock_t end = clock();
  //double time = (double)(end - begin) / CLOCKS_PER_SEC;
  //printf("%lf\n", time);
}
