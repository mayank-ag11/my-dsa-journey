/***
 * Given an array consisting of positive and negative integers, find the length of the longest subarray whose sum is zero.
 * Test cases:
 *      a: 95 -97 -387 -435 -5 -70 897 127 23 284
 *      Output: 5 [-387 -435 -5 -70 897]
 * 
 *      b: 2 -2 0 -2 2
 *      Output: 5 [2 -2 0 -2 2]
 * 
 *      c: 1 2 3 4 -10 10
 *      Output: 5 [1 2 3 4 -10]
 ***/
#include <unordered_map>
int lengthOfLongestSubsetWithZeroSum(int* arr, int n) {
    unordered_map<int, int> map;
    map[arr[0]] = 0;
    // Using arr as a prefix array
    for(int i = 1; i < n; i++) {
        arr[i] += arr[i - 1];
        map[arr[i]] = i;
    }
    
    int max_subarray = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] == 0) {
            int curr_subarray = i + 1;
            if(curr_subarray > max_subarray)
                max_subarray = curr_subarray;
        }
        else if(map[arr[i]] > i) {
            int curr_subarray = map[arr[i]] - i;
            if(curr_subarray > max_subarray)
                max_subarray = curr_subarray;
        }
    }
    return max_subarray;
}

// Java
import java.util.HashMap;
public class Solution {
    /*
     * Time complexity: O(N)
     * Space complexity: O(N)
     *
     * where N is the size of the input array
     */
    public static int lengthOfLongestSubsetWithZeroSum(int arr[]) {
        HashMap < Integer, Integer > map = new HashMap < > ();
        int n = arr.length;
        for (int i = 1; i < n; i++) {
            arr[i] += arr[i - 1];
        }
        int len = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                if (len < i + 1) {
                    len = i + 1;
                }
            } else if (map.containsKey(arr[i])) {
                if (len < i - map.get(arr[i])) {
                    len = i - map.get(arr[i]);
                }
            } else {
                map.put(arr[i], i);
            }
        }
        return len;
    }
}