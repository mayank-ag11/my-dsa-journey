/***
 * A thief wants to loot houses. He knows the amount of money in each house.
 * He cannot loot two consecutive houses. Find the maximum amount of money he can loot.
 * Test case:
    n = 6 [5, 5, 10, 100, 10, 5]
    => 110
 ***/

// DP Better - T: O(n), S: O(n)
int maxMoneyLooted(int *arr, int n) {
    if(n == 0)
        return 0;
    if(n == 1)
        return arr[0];

    int *dp = new int[n];
    dp[0] = arr[0];
    dp[1] = max(arr[0], arr[1]);

    for(int i = 2; i < n; i++) {
        dp[i] = max(dp[i - 1], arr[i] + dp[i - 2]);
    }

    return dp[n - 1];
}

// DP - T: O(n), S: O(n)
int maxMoneyLooted(int *arr, int n) {
    // dp[i][b] => b is boolean, canInclude or not
    int **dp = new int*[n + 1];
    for(int i = 0; i <= n; i++) {
        dp[i] = new int[2];
    }

    // 0 is for not included, 1 is for included
    dp[n][0] = 0;
    dp[n][1] = 0;

    for(int i = n - 1; i >= 0; i--) {
        int includeCurr = dp[i + 1][0] + arr[i];
        int excludeCurr = dp[i + 1][1];

        dp[i][0] = excludeCurr;
        dp[i][1] = max(includeCurr, excludeCurr);
    }

    return dp[0][1];
}

// Memoization - T: O(n), S: O(n)
int maxMoneyLooted(int *arr, int n, bool canInclude, int **dp) {
    if(n == 0)
        return 0;
    
    // Check if ans already exists
    if(dp[n][canInclude] != -1)
        return dp[n][canInclude];

    if(!canInclude)
        return maxMoneyLooted(arr + 1, n - 1, !canInclude, dp);
    
    // Recursive Calls
    int includeCurr = arr[0] + maxMoneyLooted(arr + 1, n - 1, !canInclude, dp);
    int excludeCurr = maxMoneyLooted(arr + 1, n - 1, canInclude, dp);

    // Save and return
    dp[n][canInclude] = max(includeCurr, excludeCurr);
    return dp[n][canInclude];
}

int maxMoneyLooted(int *arr, int n) {
    // dp[i][b] => b is boolean, canInclude or not
    int **dp = new int*[n + 1];
    for(int i = 0; i <= n; i++) {
        dp[i] = new int[2];
        for(int j = 0; j < 2; j++)
            dp[i][j] = -1;
    }
    return maxMoneyLooted(arr, n, true, dp);
}

// Java
/*
Time Complexity : O(n)
Space Complexity : O(n)
Where 'n' is the total number of houses
*/
public class Solution {
    public static int maxMoneyLooted(int[] houses) {
        int n = houses.length;
        //Special case
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return houses[0];
        }
        int[] maxMoneyCanBeLooted = new int[n];
        maxMoneyCanBeLooted[0] = houses[0];
        maxMoneyCanBeLooted[1] = Math.max(houses[0], houses[1]);
        for (int currHouse = 2; currHouse < n; currHouse++) {
            maxMoneyCanBeLooted[currHouse] = Math.max(maxMoneyCanBeLooted[currHouse -
                1], (houses[currHouse] + maxMoneyCanBeLooted[currHouse - 2]));
        }
        return maxMoneyCanBeLooted[n - 1];
    }
}