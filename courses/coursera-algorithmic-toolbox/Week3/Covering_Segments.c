#include <stdio.h>
#include <stdlib.h>

struct Segment{
  int start, end;
};

int cmpfunc(const void*a, const void*b){
  int l = ((struct Segment*)a)->end;
  int r = ((struct Segment*)b)->end;
  return l>r;
}

int Optimal_Points(struct Segment segment[], int n, int *points)
{
  int point = segment[0].end, ctr=1;
  points[0] = point;

  for(int i=1;i<n;i++)
  {
    if(point<segment[i].start||point>segment[i].end)
    {
      point = segment[i].end;
      points[ctr++] = point;
    }
  }
  return ctr;
}
int main()
{
  int n;
  scanf("%d", &n);
  struct Segment segment[n];
  for(int i=0;i<n;i++)
    scanf("%d %d", &segment[i].start, &segment[i].end);

  qsort(segment, n, sizeof(struct Segment), cmpfunc);

  int points[n];
  n = Optimal_Points(segment, n, points);

  printf("%d\n%d", n, points[0]);
  for(int i=1;i<n;i++)
    printf(" %d", points[i]);
  printf("\n");
}
