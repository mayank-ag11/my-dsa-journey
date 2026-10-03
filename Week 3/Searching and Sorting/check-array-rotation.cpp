/***
 * You have been given an integer array/list(ARR) of size N. It has been sorted(in increasing order) and then rotated by some number 'K' in the right hand direction.
 * 
 * Your task is to write a function that returns the value of 'K', that means, the index from which the array/list has been rotated.
 * 
 * Used the algorithms from codequotient (second sem)
 ***/

// Second Attempt (Hopefully better)
int countRotations(int arr[], int low, int high)
{
    /*
    // This condition is needed to handle the case
    // when the array is not rotated at all
    if (high < low)
        return 0;

    // If there is only one element left
    if (high == low)
        return 0;        
    */
    
    // Base Case
    if (high <= low)
        return 0;
    
    // Find mid
    int mid = low + (high - low)/2; // (low + high) / 2;

    // Check if element (mid+1) is minimum element.
    // Consider the cases like {3, 4, 5, 1, 2}
    if (mid < high && arr[mid+1] < arr[mid])
       return (mid+1);

    // Check if mid itself is minimum element
    if (mid > low && arr[mid] < arr[mid - 1])
       return mid;

    // Decide whether we need to go to left half or
    // right half
    if (arr[high] > arr[mid])
       return countRotations(arr, low, mid-1);

    return countRotations(arr, mid+1, high);
}
int arrayRotateCheck(int *arr, int n)
{
    return countRotations(arr, 0, n-1);
}

// First Attempt
/*int search(int arr[], int l, int r)
{
  if (r >= l) {
    int mid = l + (r - l)/2;
    if (arr[mid]<arr[0])  return mid;
    else
    return search(arr, mid+1, r);
  }
  return -1;
}

int arrayRotateCheck(int *arr, int n)
{
    int x = search(arr, 0, n-1);
    if(x == -1)
        return 0;
    while(arr[x] >= arr[x-1])
    	x--;
    return x;
}*/