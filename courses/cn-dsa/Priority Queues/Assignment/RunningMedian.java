/***
 * You are given a stream of 'N' integers. For every 'i-th' integer added to the running list of integers, print the resulting median.
 * Print only the integer part of the median.
 * Read this: https://www.geeksforgeeks.org/median-of-stream-of-running-integers-using-stl/
 ***/
/*
Time Complexity: O(N * log(N))
Space Complexity: O(N)
where N is the number of integers.
*/
import java.util.Comparator;
import java.util.PriorityQueue;
public class RunningMedian {
    public static void findMedian(int arr[]) {
        int n = arr.length;
        PriorityQueue < Integer > lowerHalf = new PriorityQueue < > (new Comparator < Integer >
            () {
                @Override
                public int compare(Integer first, Integer second) {
                    return (second - first);
                }
            });
        PriorityQueue < Integer > higherHalf = new PriorityQueue < > ();
        int median;
        //size is the size of the current stream
        for (int size = 1; size <= n; size++) {
            if (!lowerHalf.isEmpty() && lowerHalf.peek() > arr[size - 1]) {
                lowerHalf.add(arr[size - 1]);
                if (lowerHalf.size() > higherHalf.size() + 1) {
                    higherHalf.add(lowerHalf.poll());
                }
            } else {
                higherHalf.add(arr[size - 1]);
                if (higherHalf.size() > lowerHalf.size() + 1) {
                    lowerHalf.add(higherHalf.poll());
                }
            }
            if (size % 2 == 1) {
                if (higherHalf.size() > lowerHalf.size()) {
                    median = higherHalf.peek();
                } else {
                    median = lowerHalf.peek();
                }
            } else {
                median = (lowerHalf.peek() + higherHalf.peek()) / 2;
            }
            System.out.print(median + " ");
        }
    }
}