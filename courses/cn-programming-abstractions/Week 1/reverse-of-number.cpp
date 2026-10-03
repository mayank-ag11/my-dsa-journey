#include<iostream>
using namespace std;

int main() {
	int n;
    cin >> n;
    
    int res = 0, r;
    while(n) {
        r = n % 10;
        res = res * 10 + r;
        n /= 10;
    }
    
    cout << res;
}
