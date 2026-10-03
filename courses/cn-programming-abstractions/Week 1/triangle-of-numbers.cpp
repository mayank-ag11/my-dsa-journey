/***
 * Pattern (n = 4):
       1
      232
     34543
    4567654
***/
#include<iostream>
using namespace std;


int main(){
    int n;
    cin >> n;
    
    int i = 1;
    while(i <= n) {
        int spaces = 1;
        while(spaces <= n-i) {
            cout << ' ';
            spaces++;
        }
        
        int j = 1;
        while(j <= i) {
            cout << i+j-1;
            j++;
        }
        
        j = i-1;
        while(j >= 1) {
            cout << i+j-1;
            j--;
        }
        cout << '\n';
        i++;
    }
}