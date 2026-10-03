/***
 * You are given an array of unique integers that contain numbers in random order. You have to find the longest possible sequence of consecutive numbers using the numbers from given array.
 * You need to return the output array which contains starting and ending element. If the length of the longest possible sequence is one, then the output array must contain only single element.
 * Note:
    1. Best solution takes O(n) time.
    2. If two sequences are of equal length, then return the sequence starting with the number whose occurrence is earlier in the array.
 * Testcase: Input => n = 7, arr = [3 7 2 1 9 8 41]
             Output => 7 9
 ***/
// Coding Ninjas Solution
// Time: O(N), Space: O(N)
import java.util.Map;
import java.util.HashMap;
import java.util.ArrayList;
public class LongestConsecutiveSequence {
    public static ArrayList < Integer > longestConsecutiveIncreasingSequence(int[] arr) {
        Map < Integer, Boolean > visitedElements = new HashMap < > ();
        Map < Integer, Integer > elementToIndexMapping = new HashMap < > ();
        for (int i = 0; i < arr.length; i++) {
            int num = arr[i];
            elementToIndexMapping.put(num, i);
            if (!visitedElements.containsKey(num)) {
                visitedElements.put(num, false);
            }
        }
        ArrayList < Integer > longestSequence = new ArrayList < > ();
        int globalMaxSequenceLength = 1;
        int globalMinStartIndex = 0;
        for (int i = 0; i < arr.length; i++) {
            int num = arr[i];
            int currentMinStartIndex = i;
            int count = 0;
            int tempNum = num;
            //Forward
            while (visitedElements.containsKey(tempNum) &&
                !visitedElements.get(tempNum)) {
                visitedElements.put(tempNum, true); //Mark Visited elements in the array as true
                count++;
                tempNum++;
            }
            //Backward
            tempNum = num - 1;
            while (visitedElements.containsKey(tempNum) &&
                !visitedElements.get(tempNum)) {
                visitedElements.put(tempNum, true); //Mark Visited elements in the array as true
                count++;
                currentMinStartIndex = elementToIndexMapping.get(tempNum);
                tempNum--;
            }
            if (count > globalMaxSequenceLength) {
                globalMaxSequenceLength = count;
                globalMinStartIndex = currentMinStartIndex;
            } else if (count == globalMaxSequenceLength) {
                if (currentMinStartIndex < globalMinStartIndex) {
                    globalMinStartIndex = currentMinStartIndex;
                }
            }
        }
        int globalStartNum = arr[globalMinStartIndex];
        longestSequence.add(globalStartNum);
        if (globalMaxSequenceLength > 1) {
            longestSequence.add(globalStartNum + globalMaxSequenceLength - 1);
        }
        return longestSequence;
    }
}