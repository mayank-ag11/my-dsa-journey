#include <stdio.h>
int search1(int arr[], int l, int r, int x)
{
    if(l<=r)
    {
        int mid=l+(r-l)/2;
        if(arr[mid]==x) return mid;
        if(arr[mid]>x) return search1(arr, l, mid-1, x);
        return search1(arr, mid+1, r,x);
    }
    return -1;
}
int search2(int arr[], int l, int r, int x)
{
    if(l<=r)
    {
        int mid=l+(r-l)/2;
        if(arr[mid]==x) return mid;
        if(arr[mid]<x) return search2(arr, l, mid-1,x);
        return search2(arr, mid+1, r,x);
    }
    return -1;
}
int search_pivot(int arr[], int l, int r)
{
    if(l<=r)
    {
        int mid=l+(r-l)/2;
        if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1]) return mid;
        
        if(arr[mid]<arr[mid-1]) return search_pivot(arr, l, mid-1);
        
        else return search_pivot(arr, mid+1, r);
    }
    return -1;
}
int main() {
	int arr[]={14,15,18,20,12,11,9,6,3,2,1};
	int n=sizeof(arr)/sizeof(arr[0]);
	int p=search_pivot(arr, 0, n-1);
	int k=3;
    int x=search1(arr, 0, p, k);
    if(x==-1)
      x=search2(arr, p+1, n, k);
	printf("%d", x);
	return 0;
}
