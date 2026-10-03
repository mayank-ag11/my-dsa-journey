/***
 * You are given two strings s and t. You need to find the longest common subsequence (lcs) in s and t.
 * Test case:
    S -> xyz
    T -> zxay
    The common subsequnces are z, x, y and xy. So, the lcs is xy i.e 2.
 ***/

// DP - T: O(mn), S: O(mn)
int lcs(string s, string t) {
    int m = s.length();
    int n = t.length();

    int **dp = new int*[m + 1];
    for(int i = 0; i <= m; i++) {
        dp[i] = new int[n + 1];
    }

    // Fill first col
    for(int i = 0; i <= m; i++)
        dp[i][0] = 0;

    // Fill first row
    for(int j = 0; j <= n; j++)
        dp[0][j] = 0;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            // lcs is the same whether we look from beginning or end
            // if(s[m - i] == t[n - j])
            if(s[i - 1] == t[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    return dp[m][n];
}

// Memoization - T: O(mn), S: O(mn)
int lcs(string s, string t, int **dp) {
    // Base Case
    if(s.size() == 0 || t.size() == 0)
        return 0;

    // Check if ans already exists
    int m = s.length();
    int n = t.length();

    if(dp[m][n] != -1)
        return dp[m][n];

    int ans;
    // Recursive Calls
    if(s[0] == t[0]) {
        ans = 1 + lcs(s.substr(1), t.substr(1), dp);
    }
    else {
        int a = lcs(s.substr(1), t, dp);
        int b = lcs(s, t.substr(1), dp);

        ans = max(a, b);
    }

    // Save the ans for future use
    dp[m][n] = ans;

    return ans;
}
int lcs(string s, string t) {
    int m = s.length();
    int n = t.length();

    int **dp = new int*[m + 1];
    for(int i = 0; i <= m; i++) {
        dp[i] = new int[n + 1];
        for(int j = 0; j <= n; j++) {
            dp[i][j] = -1;
        }
    }

    return lcs(s, t, dp); 
}

// Recursive - O(2^n)
int lcs(string s, string t) {
    // Base Case
    if(s.size() == 0 || t.size() == 0)
        return 0;

    // Recursive Calls
    if(s[0] == t[0]) {
        return 1 + lcs(s.substr(1), t.substr(1));
    }
    else {
        int a = lcs(s.substr(1), t);
        int b = lcs(s, t.substr(1));

        return max(a, b);

        // Optional
        // int c = lcs(s.substr(1), t.substr(1));
        // return max(a, max(b, c));
    }
}