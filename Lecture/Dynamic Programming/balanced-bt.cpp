/***
 * Given an integer h, find the possible number of balanced binary trees of height h.
 * You just need to return the count of possible binary trees which are balanced.
 * This number can be huge, so, return output modulus 10^9 + 7.
 * Testcases:
 * h = 3 => 15
 * h = 4 => 315
 ***/

// DP - O(h)
const int mod = 1000000007;

int balancedBTs(int h) {
    if(h <= 1)
        return 1;
    
    int *dp = new int[h + 1];
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i = 2; i <= h; i++) {
        int x = dp[i - 1];
        int y = dp[i - 2];

        // Number of BTs made by attaching subtrees of height (n - 1) at both sides of root
        int ans = (int) (((long)x * x) % mod);

        // Number of BTs made by attaching subtrees of heights (n - 1) and (n - 2) at each side of root
        int temp = (int) ((2 * (long)x * y) % mod);

        ans = (ans + temp) % mod;
        dp[i] = ans;
    }
    
    return dp[h];
}

// Brute Force - O(2^n)
const int mod = 1000000007;

int balancedBTs(int n) {
    if(n <= 1)
        return 1;
    
    int x = balancedBTs(n - 1);
    int y = balancedBTs(n - 2);
    
    // Number of BTs made by attaching subtrees of height (n - 1) at both sides of root
    int ans = (int) (((long)x * x) % mod);
    
    // Number of BTs made by attaching subtrees of heights (n - 1) and (n - 2) at each side of root
    int temp = (int) ((2 * (long)x * y) % mod);
    
    ans = (ans + temp) % mod;
    return ans;
}

// Java Solutions
/*
Time complexity: O(N)
Space complexity: O(N)
where N is the final height of the binary tree
*/
public class Solution {
    public static int balancedBTs(int height) {
        if (height == 0) {
            return 1;
        }
        int arr[] = new int[height + 1];
        arr[0] = arr[1] = 1;
        int mod = (int) Math.pow(10, 9) + 7;
        for (int i = 2; i <= height; i++) {
            // Cast to long
            long temp1 = (long)(arr[i - 1]) * arr[i - 1];
            temp1 = temp1 % mod;
            // Cast to long
            long temp2 = 2 * (long)(arr[i - 1]) * arr[i - 2];
            temp2 = temp2 % mod;
            arr[i] = (int)(temp1 + temp2) % mod;
        }
        return arr[height];
    }
}

/*
Time complexity: O(2^N)
Space complexity: O(N)
where N is the final height of the binary tree
*/
public class Solution {
    public static long balancedBTs(long n) {
        if (n <= 1) {
            return 1;
        }
        int mod = (int) Math.pow(10, 9) + 7;
        long x = balancedBTs(n - 1);
        long y = balancedBTs(n - 2);
        long temp1 = (x * x) % mod; // Number of BTs made by attaching subtrees of height (n - 1) at both sides of root
        long temp2 = (2 * x * y) % mod; // Number of BTs made by attaching subtrees of heights (n- 1) and (n - 2) at each side of root
        long ans = (temp1 + temp2) % mod;
        return ans;
    }
}