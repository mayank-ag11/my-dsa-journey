#include<iostream>
#include<cmath>

using namespace std;

int main() {
	int n;
    cin >> n;
    
    int dec = 0, j = 0;
    while(n) {
        int r = n % 10;
        dec += (r * pow(2, j++));
        n /= 10;
    }
    
    cout << dec;
}
