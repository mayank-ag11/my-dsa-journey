/***
 * Given a binary tree with N number of nodes, check if that input tree is BST (Binary Search Tree). If yes, return true, return false otherwise.
 * Duplicate elements should be kept in the right subtree.
 ***/
#include <climits>
bool isBST(BinaryTreeNode<int> *root, int min, int max) {
    if(root == NULL)
        return true;
    if(root->data < min or root->data > max)
        return false;
    
    return isBST(root->left, min, root->data - 1) and
        isBST(root->right, root->data, max);
}
bool isBST(BinaryTreeNode<int> *root) {
    return isBST(root, INT_MIN, INT_MAX);
}

// Java
public class Solution {
    // Unique elements in BST
    public static boolean isBST(BinaryTreeNode<Integer> root, int min, int max) {
        if(root == null)
            return true;

        if(root.data > min && root.data <= max) {
            boolean ans1 = isBST(root.left, min, root.data - 1);
            boolean ans2 = isBST(root.right, root.data, max);
            return ans1 && ans2;
        }
        else
            return false;
    }
    public static boolean isBST(BinaryTreeNode<Integer> root) {
        return isBST(root, Integer.MIN_VALUE, Integer.MAX_VALUE);
    }
}

/* 
// My first try
// Failed on this test case: 4 2 6 1 10 5 7 -1 -1 -1 -1 -1 -1 -1 -1
bool isBST(BinaryTreeNode<int> *root) {
	if(root == NULL)
        return true;
    
    if(root->left != NULL and root->data <= root->left->data)
        return false;
    if(root->right != NULL and root->data > root->right->data)
        return false;
    
    return isBST(root->left) and isBST(root->right);
}*/