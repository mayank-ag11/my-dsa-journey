/***
 * Pattern for N=6     Pattern for N=3
    *1*2*3              *1*
    *4*5*               *2
    *6*7                *
    *8*
    *9
    * 
 ***/
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    
    int a = 1;
    for(int i=n; i>=1; i--) {
        for(int j=1; j<=i/2; j++) {
            cout << '*' << a;
            a++;
        }
        if(i % 2 == 1)
            cout << '*';
        cout << '\n';
    }
}