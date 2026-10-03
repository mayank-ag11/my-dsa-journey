/***
 * Given an array with N elements, you need to find the length of the longest subsequence in the given array 
 * such that all elements of the subsequence are sorted in strictly increasing order.
 * Test case:
    n = 6, [5 4 11 1 16 8] => 3 i.e [5 11 16] or [4 11 16]
 ***/

// DP - T: O(n^2), S: O(n)
int longestIncreasingSubsequence(int* arr, int n) {
    if(n == 0)
        return 0;

    int *dp = new int[n];
    // dp[i] => length of lis ending at index i

    dp[0] = 1;
    int ans = 1;
    for(int i = 1; i < n; i++) {
        int max = 1;
        for(int j = 0; j < i; j++) {
            if(arr[i] > arr[j] and dp[j] >= max)
                max = dp[j] + 1;
        }
        dp[i] = max;
        if(max > ans)
            ans = max;
    }
    
    return ans;
}