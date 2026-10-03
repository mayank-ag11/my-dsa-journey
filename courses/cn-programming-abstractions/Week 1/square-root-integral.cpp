#include<iostream>
using namespace std;

int main() {
	int n;
    cin >> n;
    
    int i = 1, res = 1;
    while(res <= n) {
        i++;
        res = i * i;
    }
    cout << i - 1;
}
