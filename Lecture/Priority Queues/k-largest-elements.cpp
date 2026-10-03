/***
 * You are given with an integer k and an array of integers that contain numbers in random order. Write a program to find k largest numbers from given array. You need to save them in an array and return it.
 * Time complexity should be O(nlogk) and space complexity should be not more than O(k).
 * Order of elements in the output is not important.
 ***/
#include <queue>
vector<int> kLargest(int input[], int n, int k){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < k; i++)
        pq.push(input[i]);
    
    int j = 0;
    for(int i = k; i < n; i++) {
        pq.push(input[i]);
        input[j++] = pq.top();
        pq.pop();
    }
    
    vector<int> ans;
    while(!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;
}

// Java
import java.util.ArrayList;
import java.util.PriorityQueue;
public class Solution {
    public static ArrayList < Integer > kLargest(int input[], int k) {
        PriorityQueue < Integer > pq = new PriorityQueue < Integer > ();
        for (int i = 0; i < k; i++) {
            pq.add(input[i]);
        }
        for (int i = k; i < input.length; i++) {
            if (input[i] > pq.peek()) {
                pq.poll();
                pq.add(input[i]);
            }
        }
        ArrayList < Integer > output = new ArrayList < Integer > ();
        while (!pq.isEmpty()) {
            output.add(pq.poll());
        }
        return output;
    }
}