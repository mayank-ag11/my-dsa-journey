/***
 * Given k different arrays, which are sorted individually (in ascending order). You need to merge all the given arrays such that output array should be sorted (in ascending order).
 ***/
#include <queue>
typedef pair<int, int> pi;

vector<int> mergeKSortedArrays(vector<vector<int>*> input) {
    vector<int> ans;
    if(input.size() == 0)
        return ans;
    
    // using min-heap of pairs, first => value, second => vector index
    priority_queue<pi, vector<pi>, greater<pi> > pq;
    
    for(int i = 0; i < input.size(); i++) {
        pi p(input[i]->at(0), i);
        pq.push(p);
        // pq.push(make_pair(input[i]->at(0), i));
    }
    
    // array to store the current index of each vector in input
    int arr[input.size()] = {0};
    
    while(!pq.empty()) {
        pi p = pq.top();
        pq.pop();
        
        ans.push_back(p.first);
        
        int v_index = p.second;
        arr[v_index]++;
        if(arr[v_index] < input[v_index]->size()) {
            pq.push(make_pair(input[v_index]->at(arr[v_index]), v_index));
        }
    }
    return ans;
}