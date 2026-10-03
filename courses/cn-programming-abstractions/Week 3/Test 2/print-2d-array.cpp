/***
 * Given a 2D integer array with n rows and m columns. Print the 0th row from input n times, 1st row n-1 times…..(n-1)th row will be printed 1 time.
 ***/
#include <iostream>
using namespace std;

void print2DArray(int **arr, int m, int n) {
    // m - row, n - col
    int k;
	for(int i=0; i<m; i++) {
        k = m - i;
        while(k--) {
            for(int j=0; j<n; j++)
                cout << arr[i][j] << ' ';
            cout << '\n';
        }
    }
}