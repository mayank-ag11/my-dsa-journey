/***
 * You will be given two arrays of same size. You can make changes only in the first array. You can add X (X can be negative as well) to elements of first array.
 * 
 * Given that an index i is said to be matching, if element at index i is same at both first array and second array. Can you tell us what is the maximum number of matchings that can be achieved.
 ***/
#include<bits/stdc++.h>
using namespace std;
// O(n)
int max_matchings_using_hashmap(int *arr1, int *arr2, int n) {
    map<int, int> match;
    for(int i=0; i<n; i++) {
        int num = arr2[i] - arr1[i];
        match[num]++;
    }
    
    int max = 0;
    map<int, int> :: iterator i;
    for(i = match.begin(); i != match.end(); i++) {
        if(i->second > max)
            max = i->second;
    }
    return max;
}
// O(nlogn)
int max_matchings(int *arr1, int *arr2, int n) {
    if(n < 2)
        return n;
    
    for(int i=0; i<n; i++)
        arr1[i] = arr2[i] - arr1[i];    
    int max = 1, curr_max = 0;
    sort(arr1, arr1+n);
    
    int i = 0, j = 0;
    while(i < n) {
        if(arr1[i] == arr1[j])
            curr_max++;
        else {
            if(curr_max > max)
                max = curr_max;
            curr_max = 1;
            j = i;
        }
        i++;
    }
    if(curr_max > max)
        max = curr_max;
    return max;
}

int main() {
    int n;
    cin >> n;
    int *arr1 = new int[n];
    int *arr2 = new int[n];
    for(int i=0; i<n; i++)
        cin >> arr1[i];
    for(int j=0; j<n; j++)
        cin >> arr2[j];
    
    int max = max_matchings(arr1, arr2, n);
    cout << max;
}
