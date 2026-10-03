// Print first n terms of the series 3N + 2 which are not multiples of 4
#include<iostream>
using namespace std;

int main() {
	int n;
    cin >> n;
    
    int j = 1;
    for(int i=1; i<=n; i++, j++) {
        int res = 3 * j + 2;
        if(res % 4 == 0) {
            i--;
            continue;
        }
        cout << res << " ";
    }
}
