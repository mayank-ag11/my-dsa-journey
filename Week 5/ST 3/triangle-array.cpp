/***
 * Harshit gave an array to Aahad and asked to make a triangle and calculate the topmost element of this array. For each layer, the element is the sum of two number below them and last layer is the given array.
 * For Example, for the array {1, 2, 3, 4}, the triangle will be:
            20
          8   12
       3    5    7
    1    2    3     4
 * The Last layer is an array and each element is the sum of two numbers below. Your task is to find the top element of the array. As the element is very large, print answer modulo 1000000007.
 ***/
#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int *arr = new int[n];
    for(int i=0; i<n; i++)
        cin >> arr[i];
    
    if(n == 0)
        cout << n;
    else if(n == 1)
        cout << arr[0];
    else {
        int curr = arr[0], next = arr[1];
        
        while(n != 1) {
            for(int i=0; i<n-1; i++) {
                curr = arr[i];
                next = arr[i+1];
                arr[i] = (curr + next) % 1000000007;
            }
            n--;
        }
        cout << arr[0];
    }
}