/***
 * For a given Binary Tree of type integer and a number K, print out all root-to-leaf paths where the sum of all the node data along the path is equal to K.
 * Input: https://files.codingninjas.in/binary-tree-page-2-1-4808.png
 * Output: 2 3 4 4
           2 3 8
    (2 9 2 is not the answer as it doesn't end at leaf.)
 ***/
/*
Time complexity: O(N * log(N))
Space complexity: O(H)
where N is the number of nodes in the input tree
and H is the height of the input tree
*/
#include <vector>
void rootToLeafPathsSumToKHelper(BinaryTreeNode<int> *root, vector<int> &path, int k) {
    if (root == NULL)
        return;

    k -= root -> data;
    path.push_back(root -> data);
    if (root -> left == NULL && root -> right == NULL) {
        if (k == 0) {
            for (int i = 0; i < path.size(); i++) {
                cout << path[i] << " ";
            }
            cout << endl;
        }
        path.pop_back();
        return;
    }
    rootToLeafPathsSumToKHelper(root -> left, path, k);
    rootToLeafPathsSumToKHelper(root -> right, path, k);
    path.pop_back();
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k) {
    vector<int> path;
    rootToLeafPathsSumToKHelper(root, path, k);
}

// Java Solution
/*
Time complexity: O(N)
Space complexity: O(H)
where N is the number of nodes in the input tree
and H is the height of the input tree
*/
public class Solution {
    private static void rootToLeafPathsSumToK(BinaryTreeNode < Integer > root, int k, String path, int currSum) {
        if (root == null)
            return;

        if (root.left == null && root.right == null) {
            currSum += root.data;
            if (currSum == k) {
                System.out.println((path + root.data + " "));
            }
            return;
        }
        rootToLeafPathsSumToK(root.left, k, (path + root.data + " "), (currSum +
            root.data));
        rootToLeafPathsSumToK(root.right, k, (path + root.data + " "), (currSum +
            root.data));
    }
    public static void rootToLeafPathsSumToK(BinaryTreeNode < Integer > root, int k) {
        rootToLeafPathsSumToK(root, k, "", 0);
    }
}