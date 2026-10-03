#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*At first the result was stored in array and then printed,
but the array was unable to store values greater than 10^8 as
it exceed the memory limits. So, better to directly print the answer.
*/
void Distribution(double  n)
{
  double n1 = sqrt((n*8+1)/4);
  int no = (int) (n1 - 0.5);
  printf("%d\n", no);
  for(int i=0;i<no-1;i++)
   // arr[i] = i+1; 
   printf("%d ", i+1);

  int k = no - 1;
  int sum = (k * (k+1))/2;
  //arr[no-1] = n - sum;
  printf("%d\n", (int)n-sum);
  //return no;
}
int main()
{
  int n;
  scanf("%d", &n);

  if(n==0)
   printf("0\n");
  else
  {
   Distribution(n);
   // int arr[n/2];
   // n = Distribution(arr, n);
  
   // printf("%d\n%d", n, arr[0]);
   // for(int i=1;i<n;i++)
   // printf(" %d", arr[i]);
   // printf("\n");
  }
}
