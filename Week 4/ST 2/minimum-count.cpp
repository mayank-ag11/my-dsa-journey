/***
 * Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
 * That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as 1 is the minimum count of numbers required.
 * Articles Read:
 * https://www.geeksforgeeks.org/minimum-number-of-squares-whose-sum-equals-to-given-number-n/
 ***/
// Approach discussed in class (Webinar 16)
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