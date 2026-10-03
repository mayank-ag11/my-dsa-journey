/***
 * https://www.geeksforgeeks.org/binary-search/
 * https://www.geeksforgeeks.org/binary-search-preferred-ternary-search/
 ***/
int binarySearch(int *arr, int n, int val)
{
    int l = 0, r = n - 1;
    while(l <= r) {
        int mid = l + (r-l)/2;
        if(arr[mid] == val)
            return mid;
        else if(arr[mid] > val)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}