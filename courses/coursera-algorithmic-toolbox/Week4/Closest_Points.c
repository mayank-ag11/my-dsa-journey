//O(n(logn)^2) method

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

struct Points{
  int x, y;
};

int compareX(const void * a, const void * b) {
   int l = ((struct Points*)a)->x;
   int r = ((struct Points*)b)->x;
   //Doubt : (r-l) vs r>l
   return l>r;
}

int compareY(const void * a, const void * b) {
   int l = ((struct Points*)a)->y;
   int r = ((struct Points*)b)->y;
   //Doubt : (r-l) vs r>l
   return l>r;
}

// Utility fn to find the dist b/w two points
double dist(struct Points p1, struct Points p2)
{
   return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

// Brute Force method to return the smallest dist b/w two points
double BruteForce(struct Points point[], int n)
{
  double min = FLT_MAX;
  for(int i=0; i<n; i++)
    for(int j=i+1; j<n; j++)
    {
        double d = dist(point[i], point[j]);
        if(d < min)
         min = d;
    }
  return min;
}

// Utility fn to find minimum of two double values
double min(double x, double y)
{
  return (x < y)? x : y;
}

// Utility fn to find the dist b/w the closest points of strip
// This method seems to be O(n^2) but it's O(n)
// as the inner loop runs at most 6 times
double stripClosest(struct Points strip[], int n, double d)
{
  double min = d;

  qsort(strip, n, sizeof(struct Points), compareY);

  // Pick all points one by one and try the next points
  // till the difference between y coordinates is smaller than d.
  // This is a proven fact that this loop runs at most 6 times
  for(int i=0; i<n; i++)
    for(int j=i+1; j<n && (strip[j].y - strip[i].y) < min; j++)
    {
       double dis = dist(strip[i], strip[j]);
       if(dis < min)
        min = dis;
    }
  return min;
}

// A recursive function to find the
// smallest distance. The array P contains
// all points sorted according to x coordinate
double Closest_Point(struct Points point[], int n)
{
  if(n<=3)
   return BruteForce(point, n);

  // Find the middle point
  int mid = n/2;
  struct Points midpoint = point[mid];

  // Divide
  double dl = Closest_Point(point, mid);
  double dr = Closest_Point(point + mid, n - mid);

  double d = min(dl,dr);

  // Building the middle strip(closer than d)
  struct Points strip[n];
  int j = 0;
  for(int i=0;i<n;i++)
    if(abs(point[i].x - midpoint.x) < d)
      strip[j++] = point[i];

  return min(d, stripClosest(strip, j, d));
}
int main()
{
  int n;
  scanf("%d", &n);

  struct Points point[n];
  for(int i=0;i<n;i++)
   scanf("%d %d", &point[i].x, &point[i].y);

  qsort(point, n, sizeof(struct Points), compareX);

  double res = Closest_Point(point, n);
  printf("%f\n", res);
}
