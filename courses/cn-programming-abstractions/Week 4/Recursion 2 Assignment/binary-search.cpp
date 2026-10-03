int binarySearch(int arr[], int l, int r, int x) {
    if(l <= r) {
        int mid = l + (r-l)/2;
        
        if(arr[mid] == x)
            return mid;
        if(arr[mid] > x)
            return binarySearch(arr, l, mid-1, x);
        return binarySearch(arr, mid+1, r, x);
    }
    return -1;
}

int binarySearch(int input[], int size, int element) {
	binarySearch(input, 0, size-1, element);
}