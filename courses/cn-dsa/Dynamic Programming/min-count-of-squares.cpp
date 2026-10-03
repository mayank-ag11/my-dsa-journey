/***
 * Given an integer N, find and return the count of minimum numbers required to represent N as a sum of squares.
 * That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum count of numbers required to represent N as sum of squares.
 * Articles: https://www.geeksforgeeks.org/minimum-number-of-squares-whose-sum-equals-to-given-number-n/
 ***/
// DP - O(n)
int minCount(int n) {
    if(sqrt(n) - floor(sqrt(n)) == 0)
        return 1;
    
	if(n <= 3)
        return n;
    
    int *dp = new int[n + 1];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    
    for(int i = 4; i <= n; i++) {
        int ans = dp[i - 1] + 1;
        for(int j = 2; j <= sqrt(i); j++)
            ans = min(ans, dp[i - j * j] + 1);
        dp[i] = ans;
    }
    return dp[n];
}

// Memoization - O(n)
int minCount(int n, int *dp) {
    if(sqrt(n) - floor(sqrt(n)) == 0)
        return 1;
    
	if(n <= 3)
        return n;
    
    if(dp[n] != -1)
        return dp[n];
    
    int ans = n;
    for(int i = 2; i <= sqrt(n); i++) {
        ans = min(ans, minCount(n - i * i, dp) + 1);
    }
    dp[n] = ans;
    return ans;
}
int minCount(int n) {
    int *dp = new int[n + 1];
    for(int i = 0; i <= n; i++)
        dp[i] = -1;
    
    return minCount(n, dp);
}

// Brute Force
int minCount(int n) {
    if(sqrt(n) - floor(sqrt(n)) == 0)
        return 1;
    
	if(n <= 3)
        return n;
    
    int ans = n;
    for(int i = 1; i <= sqrt(n); i++) {
        ans = min(ans, minCount(n - i * i) + 1);
    }
    
    return ans;
}

// Approach discussed in Programming-Abstractions class (Webinar 16)
#include<cmath>
int minCount(int n) {
    if(sqrt(n) - floor(sqrt(n)) == 0)
        return 1;
    if(n <= 3)
        return n;
    
    int i = 1, minans = n;
    
    while((n - i*i) >= 0) {
        int ans = minCount(n - i*i);
        minans = min(minans, ans + 1);
        i++;
    }
    
    return minans;
}

// From GeeksforGeeks
#include<cmath>
int minCount(int n){
    if(sqrt(n) - floor(sqrt(n)) == 0)
        return 1;
    if(n <= 3)
        return n;
    
    int res = n;
    for(int i = 1; i<=n; i++) {
        int t = i * i;
        if(t > n)
            break;
        else
            res = min(res, 1 + minCount(n - t));
    }
    return res;
}