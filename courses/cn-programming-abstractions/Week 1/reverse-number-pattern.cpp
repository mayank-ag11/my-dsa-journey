/***
 * Pattern (n = 4):
    1
    21
    321
    4321
***/
#include<iostream>
using namespace std;


int main(){
    int n;
    cin >> n;
    
    int i = 1, j;
    while(i <= n) {
        j=1;
        while(j <= i) {
            cout << i - j + 1;
            j++;
        }
        cout << '\n';
        i++;
    }
}