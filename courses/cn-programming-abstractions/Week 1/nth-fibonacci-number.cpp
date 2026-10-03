#include<iostream>
using namespace std;


int main(){
    int a = 1;
    int b = 1;
    int n;
    cin >> n;
    
    while(n > 2) {
        int t = a + b;
        a = b;
        b = t;
        n--;
    }
    cout << b;
}
