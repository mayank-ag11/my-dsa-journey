#include <stdio.h>
int search(int arr[], int l, int r)
{
    if(l<=r)
    {
        int mid=l+(r-l)/2;
        if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1]) return mid;
        
        if(arr[mid]<arr[mid-1]) return search(arr, l, mid-1);
        
        else return search(arr, mid+1, r);
    }
    return -1;
}
int main() {
	int arr[]={9,11,12,14,15,18,20,6,3,2,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	int x=search(arr, 0, n-1);
	printf("%d", x);
	return 0;
}
