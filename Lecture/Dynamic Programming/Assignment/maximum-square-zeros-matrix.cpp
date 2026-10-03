/***
 * Given an NxM matrix that contains only 0s and 1s, find out the size of the maximum square sub-matrix with all 0s.
 * You need to return the size of the square matrix with all 0s.
 * Test Cases:
    a.  3 3
        1 1 0
        1 1 1
        1 1 1
    => 1

    b.  4 4
        0 0 0 0
        0 0 0 0
        0 0 0 0
        0 0 0 0
    => 4
 * Help: Check the notes or the hint video.
 ***/

// DP - T: O(m * n), S: O(m * n)
int findMaxSquareWithAllZeros(int **arr, int n, int m) {
    // dp[i][j] = length of largest square ending at (i, j) with all zeroes
	int **dp = new int*[n];
    for(int i = 0; i < n; i++)
        dp[i] = new int[m];

    // Filling the first row
    for(int j = 0; j < m; j++)
        dp[0][j] = !arr[0][j];

    // Filling the first col
    for(int i = 0; i < n; i++)
        dp[i][0] = !arr[i][0];

    // Filling the rest
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(arr[i][j] == 1)
                dp[i][j] = 0;
            else
                dp[i][j] = 1 + min(dp[i - 1][j - 1], 
                        min(dp[i - 1][j], dp[i][j - 1]));
        }
    }

    // Find the maximum value in dp
    int max = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(max < dp[i][j])
                max = dp[i][j];
        }
    }

    return max;
}

// Java Solution
/*
Time Complexity: O(m*n)
Space Complexity: O(m*n)
where m is number of rows and n is number of columns
*/
public class Solution {
    public static int findMaxSquareWithAllZeros(int[][] input) {
        int max = 0;
        if (input.length == 0) {
            return 0;
        }
        int[][] array = new int[input.length][input[0].length];
        for (int i = 0; i < input.length; i++) {
            if (input[i][0] == 0) {
                array[i][0] = 1;
                max = 1;
            } else
                array[i][0] = 0;
        }
        for (int j = 0; j < input[0].length; j++) {
            if (input[0][j] == 0) {
                array[0][j] = 1;
                max = 1;
            } else
                array[0][j] = 0;
        }
        for (int i = 1; i < input.length; i++) {
            for (int j = 1; j < input[0].length; j++) {
                if (input[i][j] == 1) {
                    array[i][j] = 0;
                } else {
                    array[i][j] = 1 + Math.min(array[i - 1][j - 1],
                        Math.min(array[i][j - 1], array[i - 1][j]));
                    if (array[i][j] > max) {
                        max = array[i][j];
                    }
                }
            }
        }
        return max;
    }
}