/***
 * Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
 * Note:
   1. Assume the given binary tree contains all unique elements.
   2. In a pair, print the smaller element first. Order of different pairs doesn't matter.
 ***/
/*
Time complexity: O(N)
Space complexity: O(N)
where N is the number of nodes in the input tree
*/
#include <algorithm>
#include <vector>

void convertToArray(BinaryTreeNode<int>* root, vector<int> &output) {
    if (root == NULL) {
        return;
    }
    output.push_back(root -> data);
    convertToArray(root -> left, output);
    convertToArray(root -> right, output);
}
void pairSum(BinaryTreeNode<int>* root, int sum) {
    vector<int> output;
    convertToArray(root, output);
    sort(output.begin(), output.end());
    int i = 0, j = output.size() - 1;
    while (i < j) {
        if (output[i] + output[j] == sum) {
            cout << output[i] << " " << output[j] << "\n";
            ++i;
            --j;
        }
        else if (output[i] + output[j] > sum) {
            --j;
        }
        else {
            ++i;
        }
    }
}

// In Java
/*
Time complexity: O(N)
Space complexity: O(N)
where N is the number of nodes in the input tree
*/
import java.util.ArrayList;
import java.util.Collections;
public class Solution {
    public static void convertToArray(BinaryTreeNode < Integer > root, ArrayList < Integer >
        output) {
        if (root == null) {
            return;
        }
        output.add(root.data);
        convertToArray(root.left, output);
        convertToArray(root.right, output);
    }
    public static void pairSum(BinaryTreeNode < Integer > root, int sum) {
        ArrayList < Integer > output = new ArrayList < Integer > ();
        convertToArray(root, output);
        Collections.sort(output);
        int i = 0, j = output.size() - 1;
        while (i < j) {
            if (output.get(i) + output.get(j) == sum) {
                // If duplicate elements are present
                int countI = 1, countJ = 1;
                // Count the number of times 1st element is present
                int k = i + 1;
                while (output.get(k) == output.get(i)) {
                    countI++;
                    k++;
                }
                // Count the number of times 2nd element is present
                k = j - 1;
                while (output.get(k) == output.get(j)) {
                    countJ++;
                    k--;
                }
                // Print the pair count times
                int count = countI * countJ;
                while (count > 0) {
                    System.out.println(output.get(i) + " " +
                        output.get(j));
                    count--;
                }
                i += countI;
                j -= countJ;
            } else if (output.get(i) + output.get(j) > sum) {
                j--;
            } else {
                i++;
            }
        }
    }
}