/***
 * You have been given two integer arrays/lists (ARR1 and ARR2) of size N and M, respectively. You need to print their intersection.
 * An intersection for this problem can be defined when both the arrays/lists contain a particular value or to put it in other words, when there is a common value that exists in both the arrays/lists.
 * Input arrays/lists can contain duplicate elements.
 * The intersection elements printed would be in the order they appear in the first sorted array/list (ARR1).
 ***/
#include <algorithm>
#include <unordered_map>
void printIntersection(int arr1[], int arr2[], int n, int m) {
    unordered_map<int, int> map;
    for(int i = 0; i < n; i++)
        map[arr1[i]]++;
    
    // sort(arr2, arr2 + m);
    for(int i = 0; i < m; i++) {
        if(map[arr2[i]] > 0) {
            cout << arr2[i] << '\n';
            map[arr2[i]]--;
        }
    }
}

// Java
/*
Time Complexity: O(n)
Space Complexity: O(n)
where n is the size of input array
*/
import java.util.HashMap;
public class Solution {
    public static void printIntersection(int[] arr1, int[] arr2) {
        HashMap < Integer, Integer > hm = new HashMap < Integer, Integer > ();
        for (int i: arr1) {
            // if(hm.containsKey(i)) {
            // hm.put(i, hm.get(i) + 1); }
            // else {
            // hm.put(i, 1);
            // }
            hm.put(i, hm.getOrDefault(i, 0) + 1);
        }
        for (int i = 0; i < arr2.length; i++) {
            if (hm.containsKey(arr2[i])) {
                System.out.println(arr2[i]);
                if (hm.get(arr2[i]) > 1) {
                    hm.put(arr2[i], hm.get(arr2[i]) - 1);
                } else {
                    hm.remove(arr2[i]);
                }
            }
        }
    }
}