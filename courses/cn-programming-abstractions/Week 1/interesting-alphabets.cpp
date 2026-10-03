/***
 * Pattern (n = 5):
    E
    DE
    CDE
    BCDE
    ABCDE
***/
#include<iostream>
using namespace std;


int main(){
    int n;
    cin >> n;
    
    int i = 1, j;
    while(i <= n) {
        j=1;
        char start = 'A' + n - i;
        while(j <= i) {
            cout << start;
            start++;
            j++;
        }
        cout << '\n';
        i++;
    }
}