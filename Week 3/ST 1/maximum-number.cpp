/***
 * 
 ***/
// Saarthi Sood's Code
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    
    int max_num, i=1, new_num;
    while(n/i>0){
        new_num = (n/(i*10)) * i + (n%i);
        i *= 10;
        max_num = max(r,t);
    }
    cout << max_num;
}
// Mine
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;

    int arr[4];
    int i = 3;
    int num = n;
    while(num) {
        int r = num % 10;
        arr[i--] = r;
        num /= 10;
    }
    
    int max = 0;
    for(int i=0; i<4; i++) {
        int sum = 0;
        for(int j=0; j<4; j++) {
            if(j == i)
                continue;
            sum = sum * 10 + arr[j];
        }
        if(sum > max)
            max = sum;
    }
    
    cout << max;
    
    /* First Approach
    string n;
    cin >> n;
    
    int min = 10;
    int l = n.length();
    
    for(int i=0; i<l; i++) {
        int x = n[i] - '0';
        if(x < min)
            min = x;
    }
    char ch = min + '0';
    for(int i=0; i<l; i++) {
        if(n[i] == ch) {
            ch = 'a';
            continue;
        }
        cout << n[i];
    }*/
}