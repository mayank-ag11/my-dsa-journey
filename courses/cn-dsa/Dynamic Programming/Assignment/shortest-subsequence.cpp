/***
 * Gary has two string S and V. Now, Gary wants to know the length shortest subsequence in S, which is not a subsequence in V.
 * Note: The input data will be such that there will always be a solution.
 * Test case:
    S: babab V: babba => 3 (aab)
 * Help: Check notes or the hint video.
 ***/

/*
Time complexity: O(N * M)
Space compleity: O(N * M)
where N and M are the lengths of the two input strings
*/
#include <vector>

int solve(string s, string v) {
    /*
    We establish the relationship between the sub problems and the
    problem at hand. Let dp(i, j) be the length of the shortest subsequence
    that is in s[1..i] that is not in v[1..j]. Here we have the following
    relationship: dp(i, j) = ...
    1) If letter s[i] is nowhere to be found in v[1..j], then dp(i,j) = 1
    2) Otherwise, we have two case:
    2a) s[i] is in the shortest subsequence. We find k, the most
    immediate index in v[1..j] where v[k] == s[i].
    Then dp(i, j) = 1 + dp(i-1, k-1)
    2b) s[i] is not in the shortest subsequence. Then dp(i, j) = dp(i-1, j)
    We pick whichever is lower.
    */
    int n = s.length();
    int m = v.length();
    vector < vector < int >> dp(n + 1, vector < int > (m + 1));
    vector < vector < int >> next(n + 1, vector < int > (m + 1));
    for (int i = 0; i < n; i++) {
        int prev = -1;
        for (int j = 0; j < m; j++) {
            if (s[i] == v[j]) {
                prev = j;
            }
            next[i + 1][j + 1] = prev;
        }
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0] = 1;
    }
    for (int i = 0; i <= m; i++) {
        dp[0][i] = 1e9;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (next[i][j] == -1) {
                dp[i][j] = 1;
            } else {
                dp[i][j] = min(dp[i - 1][j], 1 + dp[i - 1][next[i][j]]);
            }
        }
    }
    return dp[n][m];
}

// Memoization - T: O(mn), S: O(mn)
// Still Time Limit Exceeded though:(
#include<climits>
int solve(string s, string v, int m, int n, int i, int j, int **dp, int **search) {
    if(i >= m)
        return INT_MAX;
    
    if(j >= n)
        return 1;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    // Searching for the curr char in s in v
    int index = search[i][j];
    
    // If s[i] is not present in v
    if(index == -1) {
        dp[i][j] = 1;
        return 1;
    }
    
    // If s[i] is a part of the shortest subsequence
    int a = solve(s, v, m, n, i + 1, index + 1, dp, search);
    if(a != INT_MAX)
        a++;
    
    // If s[i] is not a part of the ss
    int b = solve(s, v, m, n, i + 1, j, dp, search);
    
    dp[i][j] = min(a, b);
    return dp[i][j];
}
int solve(string s, string v) {
    int m = s.length();
    int n = v.length();

    int **dp = new int*[m];
    for(int i = 0; i < m; i++) {
        dp[i] = new int[n];
        for(int j = 0; j < n; j++)
            dp[i][j] = -1;
    }
    
    // Storing the location of char of s in v starting from each j
    int **next = new int*[m];
    for(int i = 0; i < m; i++) {
        next[i] = new int[n];
        next[i][n - 1] = -1;
        if(s[i] == v[n - 1])
            next[i][n - 1] = n - 1;
    }
    for(int i = 0; i < m; i++) {
        for(int j = n - 2; j >= 0; j--) {
            if(s[i] == v[j])
                next[i][j] = j;
            else
                next[i][j] = next[i][j + 1];
        }
    }
    
    int ans = solve(s, v, m, n, 0, 0, dp, next);
    for(int i = 0; i < m; i++)
        delete [] dp[i];
    delete [] dp;
    return ans;
}

// Second Try, better but still Time Limit Exceeded
// T: O(m * n^2), S: O(mn)
#include<climits>
int solve(string s, string v, int m, int n, int i, int j, int **dp) {
    if(i >= m)
        return INT_MAX;
    
    if(j >= n)
        return 1;
    
    if(dp[i][j] != -1)
        return dp[i][j];
    
    // Searching for the curr char in s in v
    int k;
    for(k = j; k < n; k++) {
        if(v[k] == s[i])
            break;
    }
    
    // If s[i] is not present in v
    if(k == n) {
        dp[i][j] = 1;
        return 1;
    }
    
    // If s[i] is a part of the shortest subsequence
    int a = solve(s, v, m, n, i + 1, k + 1, dp);
    if(a != INT_MAX)
        a++;
    
    // If s[i] is not a part of the ss
    int b = solve(s, v, m, n, i + 1, j, dp);
    
    dp[i][j] = min(a, b);
    return dp[i][j];
}
int solve(string s, string v) {
    int m = s.length();
    int n = v.length();

    int **dp = new int*[m];
    for(int i = 0; i < m; i++) {
        dp[i] = new int[n];
        for(int j = 0; j < n; j++)
            dp[i][j] = -1;
    }
    
    int ans = solve(s, v, m, n, 0, 0, dp);
    for(int i = 0; i < m; i++)
        delete [] dp[i];
    delete [] dp;
    return ans;
}

// First Try, very messy code
#include<climits>
int solve(string s, string v, int m, int n, int i, int j, int **dp) {
    // cout << "i = " << i << " j = " << j << '\n';
    
    if(i >= m and j >= n)
        return 0;
    if(j >= n)
        return 1;
    if(i >= m)
        return INT_MAX;
    if(dp[i][j] != -1)
        return dp[i][j];

    // If the first char of s is part of shortest subsequence
    int k;
    for(k = j; k < n; k++) {
        if(v[k] == s[i]) {
            break;
        }
    }
    if(k >= n)
        return 1;
    
    int a = solve(s, v, m, n, i + 1, k + 1, dp);
    if(a != INT_MAX)
        a++;

    // If the first char of s is not the part of ss
    int b = solve(s, v, m, n, i + 1, j, dp);

    dp[i][j] = min(a, b);
    // cout << "i = " << i << " j = " << j << " " << dp[i][j] << '\n';
    return dp[i][j];
}

int solve(string s, string v) {
    int m = s.length();
    int n = v.length();

    int **dp = new int*[m];
    for(int i = 0; i < m; i++) {
        dp[i] = new int[n];
        for(int j = 0; j < n; j++)
            dp[i][j] = -1;
    }
    
    return solve(s, v, m, n, 0, 0, dp);
}