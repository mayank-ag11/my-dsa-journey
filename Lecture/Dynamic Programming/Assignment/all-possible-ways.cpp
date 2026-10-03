/***
 * Given two integers a and b. You need to find and return the count of possible ways in which we can represent the number a as the sum of unique integers raise to the power b.
 * For example: if a = 10 and b = 2, only way to represent 10 as sum of unique integers raised to power 2 is-
    10 = 1^2 + 3^2 
   So, the answer is 1.
 ***/

/*
Time complexity: O(A ^ (1 / B))
Space complexity: O(A ^ (1 / B))
where A and B are the two given integers
*/
int power(int a, int b) {
    if (b == 0) {
        return 1;
    }
    if (b == 1) {
        return a;
    }
    int smallAns = power(a, b / 2);
    return smallAns * smallAns * power(a, b % 2);
}
int getAllWaysHelper(int a, int b, int currNum, int currSum) {
    int result = 0;
    // Calling power of 'i' raised to 'b'
    int p = power(currNum, b);
    while (p + currSum < a) {
        // Recursively check all greater values of 'i'
        result += getAllWaysHelper(a, b, currNum + 1, p + currSum);
        currNum++;
        p = power(currNum, b);
    }
    /*
    If sum of powers is equal to 'a'
    then increase the value of result
    */
    if (p + currSum == a) {
        result++;
    }
    // Return the final result
    return result;
}
int getAllWays(int a, int b) {
    return getAllWaysHelper(a, b, 1, 0);
}

// From Java Solution
int canSumTo(int k, int a, int b) {
    int rest = (int) (a - pow(k, b));
    if(rest == 0)
        return 1;
    else if(rest < 0)
        return 0;
    
    int res = 0;
    for(int i = k + 1; i < rest; i++)
        res += canSumTo(i, rest, b);

    return res;
}

int getAllWays(int a, int b) {
	int res = 0;
    for(int i = 1; i < a; i++) {
        res += canSumTo(i, a, b);
    }
    return res;
}

/*
Time complexity: O(A ^ (1 / B))
Space complexity: O(A ^ (1 / B))
where A and B are the two given integers
*/
public class Solution {
    public static int canSumTo(int k, int x, int n) {
        int rest = (int)(x - Math.pow(k, n));
        if (rest == 0) {
            return 1;
        } else if (rest < 0) {
            return 0;
        }
        int r = 0;
        for (int i = k + 1; i < rest; i++) {
            r += Solution.canSumTo(i, rest, n);
        }
        return r;
    }
    public static int allWays(int x, int n) {
        int r = 0;
        for (int i = 1; i < x; i++) {
            r += canSumTo(i, x, n);
        }
        return r;
    }
}