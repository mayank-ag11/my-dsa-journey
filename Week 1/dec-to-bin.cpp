#include<iostream>
#include<cmath>
#define ull unsigned long long int

using namespace std;

int main() {
	int n;
    cin >> n;
    
    ull bin = 0, j = 0;
    while(n) {
        int r = n % 2;
        ull c = pow(10, j++);
        bin += (r * c);
        n /= 2;
    }
    
    cout << bin;
}
