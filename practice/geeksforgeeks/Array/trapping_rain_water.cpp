#include <iostream>
using namespace std;
int ctr=0;
int min(int a, int b)
{
    if(a<b) return a;
    else return b;
}
void find(int arr[], int l, int r)
{
    int d=min(arr[l], arr[r]);
    for(int i=l+1;i<r;i++)
      {
          ctr+=(d-arr[i]);
      }
    
}
void divide(int arr[], int l, int r)
{
    int max=0, k=0;
    for(int i=l+1;i<r;i++)
    {
        if((arr[i]>arr[l]||arr[i]>arr[r])&&arr[i]>max)
        {
            max=arr[i];
            k=i;
        }
    }
    
    if(k!=0)
      {
          divide(arr, l, k);
          divide(arr, k, r);
      }
    if(k==0)
      {
          find(arr, l, r);
      }
      
}
int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    ctr=0;
	    int n;
	    cin >> n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	      cin >> arr[i];
	      
	    divide(arr, 0, n-1);
	    printf("%d\n", ctr);
	}
	return 0;
}
