/***
 * You are given an array of integers that contain numbers in random order. Write a program to find and return the number which occurs the maximum times in the given input.
 * If two or more elements contend for the maximum frequency, return the element which occurs in the array first.
 ***/
#include <unordered_map>
int highestFrequency(int arr[], int n) {
    unordered_map<int, int> map;
    for(int i = 0; i < n; i++)
        map[arr[i]]++;
    
    int max = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        if(map[arr[i]] > max) {
            max = map[arr[i]];
            ans = arr[i];
        }
    }
    return ans;
}

// Java
/*
Time Complexity: O(n)
Space Complexity: O(n)
where n is the size of input array
*/
import java.util.HashMap;
public class Solution {
    public static int maxFrequencyNumber(int[] arr) {
        HashMap < Integer, Integer > hm = new HashMap < Integer, Integer > ();
        for (int i: arr) {
            // if(hm.containsKey(i)) {
            // hm.put(i, hm.get(i) + 1); }
            // else {
            // hm.put(i, 1);
            // }
            hm.put(i, hm.getOrDefault(i, 0) + 1);
        }
        int max = 0, ans = Integer.MIN_VALUE;
        for (int i: arr) {
            if (hm.get(i) > max) {
                max = hm.get(i);
                ans = i;
            }
        }
        return ans;
    }
}