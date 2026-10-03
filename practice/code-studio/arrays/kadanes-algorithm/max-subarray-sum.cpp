/***
 * You are given an array (ARR) of length N, consisting of integers. You have to find the sum of the subarray (including empty subarray) having maximum sum among all subarrays.
 * A subarray is a contiguous segment of an array. In other words, a subarray can be formed by removing 0 or more integers from the beginning, and 0 or more integers from the end of an array.
 * The sum of an empty subarray is 0.
 ***/
/***
 * https://www.youtube.com/watch?v=KPU8-J4Vtfk
 ***/
long long maxSubarraySum(int arr[], int n) {
    long long curr_sum = 0;
    long long max_sum = 0;

    for (int i = 0; i < n; i++) {
        curr_sum += arr[i];

        if (curr_sum > max_sum)
            max_sum = curr_sum;

        if (curr_sum < 0)
            curr_sum = 0;
    }
    return max_sum;
}
/*
// First Try (got TLE)
#include<iostream>
using namespace std;

long long maxSubarraySum(int arr[], int n) {
    long long subarray_sum = arr[n-1];
    long long max_sum = max(0, arr[n-1]);

    for(int i=n-2; i>=0; i--) {
        subarray_sum = max((long long)arr[i], subarray_sum + arr[i]);

        if(subarray_sum > max_sum)
            max_sum = subarray_sum;
    }
    return max_sum;
}
*/