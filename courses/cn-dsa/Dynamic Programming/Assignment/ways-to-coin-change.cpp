/***
 * For the given infinite supply of coins of each of denominations, D = {D0, D1, D2, D3, ...... Dn-1}.
 * You need to figure out the total number of ways W, in which you can make the change for Value V using coins of denominations D.
 * Return 0 if the change isn't possible.
 * 
 * Test cases:
    a. n = 3, D = [1, 2, 3], val = 4 => 4
        i.e [1, 1, 1, 1], [1, 1, 2], [1, 3], [2, 2]
    b. n = 6, D = [1, 2, 3, 4, 5, 6], val = 250 => 13868903
 
 * Help: https://www.youtube.com/watch?v=DJ4a7cmjZY0&t=608s
 ***/

// DP - T: O(n * val), S: O(n * val)
int countWaysToMakeChange(int denominations[], int numDenominations, int value) {
    int **dp = new int*[numDenominations + 1];
    for(int i = 0; i <= numDenominations; i++)
        dp[i] = new int[value + 1];
    
    // Filling the first col
    for(int i = 0; i <= numDenominations; i++)
        dp[i][0] = 1;

    // Filling the first row
    for(int j = 1; j <= value; j++)
        dp[0][j] = 0;

    for(int i = 1; i <= numDenominations; i++) {
        for(int j = 1; j <= value; j++) {
            // Excluding the coin at (i - 1)th index
            dp[i][j] = dp[i - 1][j];

            // Including the coin at (i - 1)th index
            // if the curr value is greater than the coin
            if(j >= denominations[i - 1])
                dp[i][j] += dp[i][j - denominations[i - 1]];
        }
    }

    return dp[numDenominations][value];
}

// Java Solution
/*
Time Complexity: O(mn)
Space Complexity: O(mn)
where n is number of demoninationsa and m is the value inputted
*/
public class Solution {
    public static int countWaysToMakeChange(int denominations[], int value) {
        int n = denominations.length;
        int ways[][] = new int[n][value + 1];
        for (int i = 0; i < n; i++) {
            ways[i][0] = 1;
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= value; j++) {
                int count1 = 0;
                if (i + 1 <= n - 1) {
                    count1 = ways[i + 1][j];
                }
                int count2 = 0;
                if (j - denominations[i] >= 0) {
                    count2 = ways[i][j - denominations[i]];
                }
                ways[i][j] = count1 + count2;
            }
        }
        return ways[0][value];
    }
}

// Brute Force - T: O(n^m), S: O(m)
// m -> value, n -> numDenominations
// Not correct!!! Duplicates: [1, 2, 1], [1, 1, 2], [2, 1, 1]
int countWaysToMakeChange(int denominations[], int numDenominations, int value){
	if(value == 0)
        return 1;
    if(value < 0)
        return 0;
    
    int ans = 0;
    for(int i = 0; i < numDenominations; i++) {
        int rem = value - denominations[i];

        ans += countWaysToMakeChange(denominations, numDenominations, rem);
    }

    return ans;
}