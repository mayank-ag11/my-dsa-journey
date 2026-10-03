/***
 * You are given an array of n elements and a sum value, you have to calculate the total number of ways to calculate the given sum using the elements of the array by using only addition(+) and subtraction operator(-).
 * Discussed in class (Webinar 16)
 * https://www.geeksforgeeks.org/number-of-ways-to-calculate-a-target-number-using-only-array-elements/
 ***/
// curr_sum from 0 to sum
int helper(int* arr, int n, int sum, int curr_sum, int i) {
    if(i == n) {
        if(sum == curr_sum)
            return 1;
        else
            return 0;
    }
    
    return helper(arr, n, sum, curr_sum + arr[i], i+1) // +ve
        + helper(arr, n, sum, curr_sum, i+1)           // exclude
        + helper(arr, n, sum, curr_sum - arr[i], i+1); // -ve
}

// sum to 0
int helper(int *arr, int n, int i, int sum) {
    if(sum == 0 && i == n)
        return 1;
    if(i >= n)
        return 0;
    
    return helper(arr, n, i+1, sum)        // exclude
        + helper(arr, n, i+1, sum+arr[i])  // +ve
        + helper(arr, n, i+1, sum-arr[i]); // -ve
}

int number(int* input,int n,int sum)
{
	int x = helper(input, n, sum, 0, 0); // curr_sum -> 0 to sum
    // int x = helper(input, n, 0, sum); // sum to 0
    
    if(sum == 0)
        return x-1;
    return x;
}