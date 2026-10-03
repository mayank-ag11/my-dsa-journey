/***
 * You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k smallest numbers from given array. You need to save them in an array and return it.
 * Time complexity should be O(n * logk) and space complexity should not be more than O(k).
 * Note: Order of elements in the output is not important.
 ***/
#include <queue>
vector<int> kSmallest(int input[], int n, int k) {
    priority_queue<int> pq;
    for(int i = 0; i < k; i++)
        pq.push(input[i]);
    
    int j = 0;
    for(int i = k; i < n; i++) {
        if(input[i] < pq.top()) {
            pq.pop();
            pq.push(input[i]);
        }
    }
    
    vector<int> ans;
    while(!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}