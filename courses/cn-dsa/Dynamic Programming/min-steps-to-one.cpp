/***
 * Given a positive integer 'n', find and return the minimum number of steps that 'n' has to take to get reduced to 1. You can perform any one of the following 3 steps:
 * 
 *  1.) Subtract 1 from it. (n = n - ­1) ,
    2.) If its divisible by 2, divide by 2.( if n % 2 == 0, then n = n / 2 ) ,
    3.) If its divisible by 3, divide by 3. (if n % 3 == 0, then n = n / 3 ).  
 ***/

// DP - O(n)
int countMinStepsToOne(int n) {
    if(n == 1)
        return 0;
    
    int *dp = new int[n + 1];
    dp[1] = 0;

    for(int i = 2; i <= n; i++) {
        int a, b = INT_MAX, c = INT_MAX;
        
        a = dp[i - 1];
        if(i % 2 == 0)
            b = dp[i / 2];
        if(i % 3 == 0)
            c = dp[i / 3];

        dp[i] = min(a, min(b, c)) + 1;
    }

    return dp[n];
}

// Memoization - O(n)
#include<climits>
int countMinStepsToOne(int n, int *dp) {
    if(n == 1)
        return 0;
    
    if(dp[n] != -1)
        return dp[n];
    
    int a = countMinStepsToOne(n - 1, dp);
    int b = INT_MAX, c = INT_MAX;
    if(n % 2 == 0)
        b = countMinStepsToOne(n / 2, dp);
    if(n % 3 == 0)
        c = countMinStepsToOne(n / 3, dp);
    
    dp[n] = min(a, min(b, c)) + 1;
    return dp[n];
}

int countStepsToOne(int n)
{
	int *dp = new int[n + 1];
    for(int i = 0; i <= n; i++)
        dp[i] = -1;
    return countStepsToOne(n, dp);
}

// Brute Force - O(3^n)
#include<climits>
int countMinStepsToOne(int n)
{
	if(n == 1)
        return 0;
    
    int a = countMinStepsToOne(n - 1);
    int b = INT_MAX, c = INT_MAX;
    if(n % 2 == 0)
        b = countMinStepsToOne(n / 2);
    if(n % 3 == 0)
        c = countMinStepsToOne(n / 3);
    
    return min(a, min(b, c)) + 1;
}