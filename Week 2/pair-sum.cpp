/***
 * You have been given an integer array/list(ARR) and a number X. Find and return the total number of pairs in the array/list which sum to X.
 * Given array/list can contain duplicate elements.
 * 
 * Sample Testcase:
 * (1 3 6 2 5 4 3 2 4) X=7 --> 7
 * (1 3 6 2 5 4 3 2 4) X=12 --> 0
 * (2 8 10 5 -2 5) X=10 --> 2
 * 
 * https://www.geeksforgeeks.org/count-pairs-with-given-sum/
 ***/

// Using map to store frequency - O(n) solution
#include<unordered_map>
using namespace std;
int pairSum(int *arr, int n, int x)
{
	unordered_map<int, int> m;
 
    // Store counts of all elements in map m
    for (int i = 0; i < n; i++)
        m[arr[i]]++;
 
    int twice_count = 0;
 
    // iterate through each element and increment the
    // count (Notice that every pair is counted twice)
    for (int i = 0; i < n; i++) {
        twice_count += m[x - arr[i]];
 
        // if (arr[i], arr[i]) pair satisfies the condition,
        // then we need to ensure that the count is
        // decreased by one such that the (arr[i], arr[i])
        // pair is not considered
        if (x - arr[i] == arr[i])
            twice_count--;
    }
 
    // return the half of twice_count
    return twice_count / 2;
}

// Brute Force
int pairSum(int *arr, int n, int x)
{
	int ctr = 0;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(arr[i] + arr[j] == x)
                ctr++;
        }
    }
    return ctr;
}