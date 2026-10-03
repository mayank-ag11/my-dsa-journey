/***
 * You are given with an array of integers and an integer K. You have to find and print the count of all such pairs which have difference K.
 * Note: Take absolute difference between the elements of the array.
 ***/
#include <unordered_map>
int getPairsWithDifferenceK(int *arr, int n, int k) {
	unordered_map<int, int> map;
    
    for(int i = 0; i < n; i++)
        map[arr[i]]++;
    
    int twice_ctr = 0;
    for(int i = 0; i < n; i++) {
        twice_ctr += map[arr[i] + k];
        if(k != 0)
        	twice_ctr += map[arr[i] - k];
        
        if(arr[i] + k == arr[i] or arr[i] - k == arr[i])
            twice_ctr--;
    }
    return twice_ctr / 2;
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
    public static int getPairsWithDifferenceK(int arr[], int k) {
        HashMap < Integer, Integer > map = new HashMap < Integer, Integer > ();
        int pairCount = 0;
        for (int i: arr) {
            int p1 = i + k;
            boolean flag = false;
            if (i == p1)
                flag = true;

            if (map.containsKey(p1))
                pairCount += map.get(p1);

            int p2 = i - k;
            if (map.containsKey(p2) && !flag)
                pairCount += map.get(p2);

            if (map.containsKey(i))
                map.put(i, map.get(i) + 1);
            else
                map.put(i, 1);
        }
        return pairCount;
    }
}