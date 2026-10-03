/***
 * Take input a stream of n integer elements, find the second largest element present.
 * 
 * The given elements can contain duplicate elements as well. If only 0 or 1 element is given, the second largest should be INT_MIN ( - 2^31 ).
 ***/
#include<iostream>
using namespace std;
#include <climits>


int main(){
	int l = INT_MIN, sl = INT_MIN;
    
    int n, x;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        cin >> x;
        
        if(x > l) {
            sl = l;
            l = x;
        }
        else if(x != l && x > sl) {
            sl = x;
        }
    }
    
    cout << sl;
}