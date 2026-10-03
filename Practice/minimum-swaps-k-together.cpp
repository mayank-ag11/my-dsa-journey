/***
 * Discussed in class (Webinar 8) - Sliding Window
 * https://practice.geeksforgeeks.org/problems/minimum-swaps-required-to-bring-all-elements-less-than-or-equal-to-k-together/0
 * https://www.geeksforgeeks.org/minimum-swaps-required-bring-elements-less-equal-k-together/
 ***/
int minSwap(int *arr, int n, int k) {
    int subarray_size = 0;
    for(int i=0; i<n; i++)
        if(arr[i] <= k)
            subarray_size++;
    
    // Finding swaps in first subarray
    int s = 0, e = subarray_size-1, swaps = 0;
    for(int i=0; i<=e; i++)
        if(arr[i] > k)
            swaps++;
    
    int minSwaps = swaps;
    
    // Sliding Window
    while(e < n-1) {
        // outgoing element
        if(arr[s] > k)
            swaps--;
        // incoming element
        s++;
        e++;
        if(arr[e] > k)
            swaps++;
        if(swaps < minSwaps)
            minSwaps = swaps;
    }
    
    return minSwaps;
}