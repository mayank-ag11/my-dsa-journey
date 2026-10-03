/***
 * Given two strings s and t of lengths m and n respectively, find the edit distance between the strings.
 * Edit Distance of two strings is minimum number of operations required to make one string equal to other.
 * In order to do so you can perform any of the following three operations only :
    1. Delete a character
    2. Replace a character with another one
    3. Insert a character

 * Note: Strings don't contain spaces
 * Test case:
    [abc, dc] => 2
 ***/

// DP - T: O(mn), S: O(mn)
int editDistance(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    int **dp = new int*[m + 1];
    for(int i = 0; i <= m; i++) {
        dp[i] = new int[n + 1];
    }

    // Fill first col
    for(int i = 0; i <= m; i++)
        dp[i][0] = i;

    // Fill first row
    for(int j = 0; j <= n; j++)
        dp[0][j] = j;

    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            // editdistance is the same whether we start from beginning or end
            // if(s1[m - i] == s2[n - j])
            if(s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else {
                int a = dp[i - 1][j];
                int b = dp[i][j - 1];
                int c = dp[i - 1][j - 1];

                dp[i][j] = 1 + min(a, min(b, c));
            }
        }
    }

    return dp[m][n];
}

// Memoization - T: O(mn), S: O(mn)
int editDistance(string s1, string s2, int **dp) {
    if(s1.length() == 0)
        return s2.length();
    if(s2.length() == 0)
        return s1.length();
    
    // Check if ans already exists
    int m = s1.length();
    int n = s2.length();

    if(dp[m][n] != -1)
        return dp[m][n];

    int ans;
    // Recursive calls    
    if(s1[0] == s2[0])
        ans = editDistance(s1.substr(1), s2.substr(1), dp);
    else {
        // Insert
        int a = editDistance(s1.substr(1), s2, dp) + 1;
        // Delete
        int b = editDistance(s1, s2.substr(1), dp) + 1;
        // Replace
        int c = editDistance(s1.substr(1), s2.substr(1), dp) + 1;
        
        ans = min(a, min(b, c));
    }
    // Save the ans
    dp[m][n] = ans;
    return ans;
} 
int editDistance(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    int **dp = new int*[m + 1];
    for(int i = 0; i <= m; i++) {
        dp[i] = new int[n + 1];
        for(int j = 0; j <= n; j++) {
            dp[i][j] = -1;
        }
    }

    return editDistance(s1, s2, dp); 
}

// Recursive - O(3^n)
int editDistance(string s1, string s2) {
	if(s1.length() == 0)
        return s2.length();
    if(s2.length() == 0)
        return s1.length();
    
    if(s1[0] == s2[0])
        return editDistance(s1.substr(1), s2.substr(1));
    else {
        // Insert
        int a = editDistance(s1.substr(1), s2) + 1;
        // Delete
        int b = editDistance(s1, s2.substr(1)) + 1;
        // Replace
        int c = editDistance(s1.substr(1), s2.substr(1)) + 1;
        
        return min(a, min(b, c));
    }
}

// Java
/*
Time Complexity : O(M * N)
Space Complexity : O(M * N)
Where M and N are the lengths of string 's' and 't' respectively
*/
public class Solution {
    private static int editDistanceHelper(String s, String t, int[][] subProblems) {
        if (s.length() == 0) {
            return t.length();
        }
        if (t.length() == 0) {
            return s.length();
        }
        int m = s.length();
        int n = t.length();
        if (subProblems[m][n] != -1) {
            return subProblems[m][n];
        }
        if (s.charAt(0) == t.charAt(0)) {
            int smallAns = editDistanceHelper(s.substring(1), t.substring(1), subProblems);
            subProblems[m - 1][n - 1] = smallAns;
            subProblems[m][n] = 0 + smallAns;
        } else {
            int remove = editDistanceHelper(s.substring(1), t, subProblems);
            subProblems[m - 1][n] = remove;
            int insert = editDistanceHelper(s, t.substring(1), subProblems);
            subProblems[m][n - 1] = insert;
            int substitute = editDistanceHelper(s.substring(1), t.substring(1),
                subProblems);
            subProblems[m - 1][n - 1] = substitute;
            subProblems[m][n] = 1 + Math.min(remove, Math.min(insert, substitute));
        }
        return subProblems[m][n];
    }
    public static int editDistance(String s, String t) {
        int m = s.length();
        int n = t.length();
        int[][] subProblems = new int[(m + 1)][(n + 1)];
        //Assigning all the values with -1
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                subProblems[i][j] = -1;
            }
        }
        return editDistanceHelper(s, t, subProblems);
    }
}