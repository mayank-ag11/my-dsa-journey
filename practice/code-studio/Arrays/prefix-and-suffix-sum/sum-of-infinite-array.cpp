/***
 * Given an array “A” of N integers and you have also defined the new array “B” as a concatenation of array “A” for an infinite number of times.
 * For example, if the given array “A” is [1,2,3] then, infinite array “B” is [1,2,3,1,2,3,1,2,3,.......].
 * Now you are given Q queries, each query consists of two integers “L“ and “R”. Your task is to find the sum of the subarray from index “L” to “R” (both inclusive) in the infinite array “B” for each query.
 * Note: The value of the sum can be very large, return the answer as modulus 10^9+7.
 ***/
/*  Coding Ninjas Solution:
        Time Complexity:O(Q+N).
        Space Complexity:O(N).

    Where N is the size of the given array, and Q is the number of queries given.
*/
int mod = 1000000007;
#include <vector>
using namespace std;

// Function to calculate prefix sum upto index x of the infite array.
long long func(vector<long long> &sumArray, long long x, long long n) {

    // Number of times the given array comes completely upto index x.
    long long count = (x / n) % mod;

    long long res = (count * sumArray[(int) n]) % mod;

    // Adding the remaining elements sum.
    res = (res + sumArray[(int) (x % n)]) % mod;

    return res;
}

vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) {
    // It stores answer for each query.
    vector<int> ans;

    // It store cumulative sum where sumArray[i] = sum(A[0]+..A[i]).
    vector<long long> sumArray(n + 1);

    for (int i = 1; i <= n; i++) {
        sumArray[i] = (sumArray[i - 1] + arr[i - 1]) % mod;
    }

    // Traversing the given queries.
    for (int i = 0; i < queries.size(); i++) {
        vector<long long> range = queries[i];
        long long l = range[0];
        long long r = range[1];

        // It stores the prefix sum from index 0 to index r in an infinite array.
        long long rsum = func(sumArray, r, n);

        // It stores the prefix sum from index 0 to index l-1 in an infinite array.
        long long lsum = func(sumArray, l - 1, n);

        // Add answer for each query.
        ans.push_back((int) ((rsum - lsum + mod) % mod));
    }
    return ans;
}
/* 
// My try - failed
#define mod 1000000007
vector<int> sumInRanges(vector<int> &arr, int n, vector<vector<long long>> &queries, int q) {
    // Prefix Sum Array
    int *prefix = new int[n+1];
    prefix[0] = 0;
    for(int i = 0; i < n; i++) {
        prefix[i+1] = (prefix[i] + arr[i]) % mod;
    }    
    // Solution
    vector<int> v;
    for(int i = 0; i < q; i++) {
        int l = queries[i][0];
        int r = queries[i][1];
        
        int total = r - l + 1;
        l = l % n; if(l == 0) l = n;
        r = r % n; if(r == 0) r = n;
        
        if(total <= n && l <= r) {
            v.push_back(prefix[r] - prefix[l-1]);
        }
        else {  
            int sum = 0;
            // first portion (suffix sum)
            sum = (sum + prefix[n] - prefix[l-1]) % mod;
            
            // third portion (prefix sum)
            sum = (sum + prefix[r]) % mod;
            
            // second portion
            total = total - (n - l + 1) - r;
            total /= n;
            // sum += (prefix[n] * (total/n)) % mod;
            while(total--) {
                sum = (sum + prefix[n]) % mod;
            }
            
            sum = sum % mod;
            v.push_back(sum);
        }
    }   
    return v;
}*/