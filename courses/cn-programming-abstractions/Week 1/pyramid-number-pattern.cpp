/***
 * Pattern (n = 4):
       1
      212
     32123
    4321234
***/
#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int i = 1;
    while(i <= n) {
        int j = 1, spaces = n - i, k;
        while(j <= spaces) {
            cout << ' ';
            j++;
        }
        
        j = 1, k = i;
        while(j <= i) {
            cout << k;
            k--;
            j++;
        }
        
        k = 2, j = 1;
        while(j <= i -1) {
            cout << k;
            k++;
            j++;
        }
        
        cout << '\n';
        i++;
    }
}