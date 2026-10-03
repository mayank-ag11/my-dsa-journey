//Compute the no. of segments that contain a point
//https://www.coursera.org/learn/algorithmic-toolbox/discussions/weeks/4/threads/QJ1jK9wNEeWdPBL2iFTrAw/replies/EGc9OoGvEeaehxKamXPqUw/comments/HK3cUjuoEeeAgQrkDbjJSA

#include <stdio.h>
#include <stdlib.h>

int cmpfunc(const void *a, const void *b)
{
  return *(int*)a > *(int*)b;
}

int s;
int BinarySearch_LeftEnds(int *arr, int l, int r, int key)
{
  if(r < l)
   return -1;

  int mid = l + (r - l)/2;

  if(arr[mid]>key && arr[mid-1]<=key)
   return mid;
  else if(arr[mid]>key)
   return BinarySearch_LeftEnds(arr, l, mid-1, key);
  else
   return BinarySearch_LeftEnds(arr, mid+1, r, key);
}

int BinarySearch_RightEnds(int *arr, int l, int r, int key)
{
  if(r < l)
   return -1;

  int mid = l + (r - l)/2;

  if(arr[mid]<key && arr[mid+1]>=key)
   return mid;
  else if(arr[mid]>=key)
   return BinarySearch_RightEnds(arr, l, mid-1, key);
  else
   return BinarySearch_RightEnds(arr, mid+1, r, key);
}
int main()
{
  int p;
  scanf("%d %d", &s, &p);

  int leftends[s], rightends[s];
  for(int i=0; i<s; i++)
    scanf("%d %d", &leftends[i], &rightends[i]);

  qsort(leftends, s, sizeof(int), cmpfunc);
  qsort(rightends, s, sizeof(int), cmpfunc);

  while(p--)
  {
    int point;
    scanf("%d", &point);

    int l,r;
    if(point < leftends[0])
     l = 0;
    else if(point >= leftends[s-1])
     l = s;
    else l = BinarySearch_LeftEnds(leftends, 0, s-1, point);

    if(point <= rightends[0])
     r = s;
    else if(point > rightends[s-1])
     r = 0;
    else r = s - 1 - BinarySearch_RightEnds(rightends, 0, s-1, point);
    
    printf("%d ", l + r - s);
  }
  printf("\n");
}
