/*** N = odd always
 * Pattern (n = 4):
      *
     ***
    *****
     ***
      *
***/
#include<iostream>
using namespace std;


int main(){
    int n;
    cin >> n;
    n = n/2 + 1;
    
    int i = 1;
    while(i <= n) {
        int spaces = 1;
        while(spaces <= n-i) {
            cout << ' ';
            spaces++;
        }
        
        int j = 1, k = i*2-1;
        while(j <= k) {
            cout << "*";
            j++;
        }
        cout << '\n';
        i++;
    }
    
    // For reverse
    i = n - 1;
    while(i >= 1) {
        int spaces = 1;
        while(spaces <= n-i) {
            cout << ' ';
            spaces++;
        }
        
        int j = 1, k = i*2-1;
        while(j <= k) {
            cout << "*";
            j++;
        }
        cout << '\n';
        i--;
    }
}