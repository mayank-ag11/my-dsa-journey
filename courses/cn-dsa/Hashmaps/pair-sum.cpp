/***
 * Given a random integer array A of size N. Find and print the count of pair of elements in the array which sum up to 0.
 * Note: Array A can contain duplicate elements as well.
 ***/
#include <unordered_map>
int pairSum(int *arr, int n) {
	unordered_map<int, int> m;
    int x = 0;  // Given sum, 0 in this case
 
    // Store counts of all elements in map m
    for (int i = 0; i < n; i++)
        m[arr[i]]++;
 
    int twice_count = 0;
 
    // iterate through each element and increment the
    // count (Notice that every pair is counted twice)
    for (int i = 0; i < n; i++) {
        twice_count += m[x - arr[i]];
 
        // if (arr[i], arr[i]) pair satisfies the condition,
        // then we need to ensure that the count is
        // decreased by one such that the (arr[i], arr[i])
        // pair is not considered
        if (x - arr[i] == arr[i])
            twice_count--;
    }
 
    // return the half of twice_count
    return twice_count / 2;
}

// Java
/*
Time Complexity: O(n)
Space Complexity: O(n)
where n is the size of input array
*/
import java.util.*;
public class Solution {
    public static int PairSum(int[] input, int size) {
        HashMap < Integer, Integer > h = new HashMap < Integer, Integer > ();
        int finalCount = 0;
        for (int i = 0; i < size; i++) {
            int key = input[i];
            if (h.containsKey(key)) {
                int value = h.get(key);
                h.put(key, value + 1); //incrementing frequency value by 1 if key is already present in hashmap
            } else {
                h.put(key, 1); //initializing frequency value to 1 if key is not already present in hashmap
            }
        }
        //traversing the array and checking if -key is present in hashmap
        for (int i = 0; i < size; i++) {
            int key = input[i];
            if (h.containsKey(-key) && h.get(key) != 0) {
                int times;
                if (key == (-key)) { //True in case of zero
                    int occurences = h.get(key);
                    times = (occurences * (occurences - 1)) / 2;
                    finalCount = finalCount + times;
                    h.put(key, 0);
                    continue;
                }
                times = h.get(key) * h.get(-key);
                finalCount = finalCount + times;
                h.put(key, 0);
                h.put(-key, 0);
            }
        }
        return finalCount;
    }
}