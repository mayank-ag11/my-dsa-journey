/***
 * Pattern (n = 5):
    1234554321
    1234**4321
    123****321
    12******21
    1********1
***/
#include<iostream>
using namespace std;


int main(){
	int n;
    cin >> n;
    
    int i = 1;
    while(i <= n) {
        int j = 1, times = n - i + 1;
        while(j <= times) {
            cout << j;
            j++;
        }
        
        j = 1, times = i * 2 - 2;
        while(j <= times) {
            cout << "*";
            j++;
        }
        
        j = n - i + 1;
        while(j >= 1) {
            cout << j;
            j--;
        }
        
        cout << '\n';
        i++;
    }
}