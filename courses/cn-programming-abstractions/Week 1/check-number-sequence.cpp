/***
 * You are given S, a sequence of n integers i.e. S = s1, s2, ..., sn. Compute if it is possible to split S into two parts : s1, s2, ..., si and si+1, si+2, ….., sn (0 <= i <= n) in such a way that the first part is strictly decreasing while the second is strictly increasing one.
 *
 * Note : We say that x is strictly larger than y when x > y. So, a strictly increasing sequence can be 1 4 8. However, 1 4 4 is NOT a strictly increasing sequence.
 *
 * That is, in the sequence if numbers are decreasing, they can start increasing at one point. And once the sequence of numbers starts increasing, they cannot decrease at any point further.
 *
 * Sequence made up of only increasing numbers or only decreasing numbers is a valid sequence. So, in both the cases, print true.

***/
#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	int a, b;
	cin >> a >> b;
    
	bool is_dec = false;
	if(a>b){
		is_dec=true; //decreasing
	}
    else if(a<b){
		is_dec=false; // increasing
	}
    else{
	cout<<"false";
	return 0;
	}
    
	int i=1;
    while(i <= (n-2)){
        a = b;
        cin >> b;
        if(a > b){
        	if(is_dec == false){
        		cout << "false";
        		return 0;
        	}
        }
        else if(a < b){
        	is_dec = false;
        }
        else{
            cout << "false";
            return 0;
        }
        i++;
    }
	
    cout << "true";
    return 0;
}
