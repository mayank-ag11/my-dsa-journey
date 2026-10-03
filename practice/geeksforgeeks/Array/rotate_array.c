#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while(t--)
	{
	    int n, k;
	    scanf("%d %d", &n, &k);
	    int arr[n];
	    for(int i=0;i<n;i++)
	     scanf("%d", &arr[i]);
	    if(k>n)
	    k%=n;
	    
	    for(int i=0;i<n;i++)
	      printf("%d ", arr[(i+k)%n]);  //left rotate
	      
	    printf("\n");
	}
	return 0;
}
