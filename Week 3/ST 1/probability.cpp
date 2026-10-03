/***
 * An urn contains 8 balls : 4 red , 2 blue and 2 green. Now n balls are drawn out of the urn. Calculate the probability that out of n drawn balls exactly x balls are red.
 * Find your answer multiplied by 100 and return the integer part.
 * x is always less than equal to 4 and x is always less than equal to n.
 ***/
#include<bits/stdc++.h>
using namespace std;

int fact(int n) {
    if(n < 2)
        return 1;
    int res = 1;
    for(int i=2; i<=n; i++)
        res *= i;
    return res;
}

int nCr(int n, int r) {
    return (fact(n) / (fact(r) * fact(n-r)));
}

int main() {
    int n, x;
    cin >> n >> x;
   
    // int tp = (fact(4)/ (fact(x)*fact(4-x))) * (fact(4)/(fact(4-(n-x))*fact(n-x)));
    // int t = (fact(8)/(fact(n) * fact(8-n)));

    int tp = nCr(4, x) * nCr(4, n-x);
    int t = nCr(8, n);

    cout << (tp * 100) / t;
    
    /* // First Try - Didn't work
    int p = pow(2, n);
    int ncr = nCr(n, x);
    
    // cout << p << endl;
    // cout << ncr;
    cout << (nCr(n, x) * 100 / p); */
}
