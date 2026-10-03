/***
 * Given a Binary Search Tree and two integers k1 and k2, find and print the elements which are in range k1 and k2 (both inclusive).
 * Print the elements in increasing order.
 * Test Case: 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
              6 10
           => 6 7 8 10
 ***/
/**********************************************************
	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
***********************************************************/
void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2) {
	if(root == NULL)
        return;
    
    int n = root->data;
    if(n < k1)
        elementsInRangeK1K2(root->right, k1, k2);
    else if(n > k2)
        elementsInRangeK1K2(root->left, k1, k2);
    else {
        elementsInRangeK1K2(root->left, k1, n);
        cout << n << ' ';
        elementsInRangeK1K2(root->right, n, k2);
    }
}

// Java
public class Solution {
    /*
     * Binary Tree Node class:-
     * class BinaryTreeNode<T> { 
     *     T data; 
     *     BinaryTreeNode<T> left; 
     *     BinaryTreeNode<T> right;
     *
     *     public BinaryTreeNode(T data) {
     *         this.data = data;
     *     }
     * }
     */
    /*
     * Time complexity: O(N)
     * Space complexity: O(H)
     *
     * where N is the number of nodes in the input BST and
     * H is the height of the input BST
     */
    public static void elementsInRangeK1K2(BinaryTreeNode<Integer> root, int k1, int k2) {
        if (root == null)
            return;

        if (root.data >= k1 && root.data <= k2) {
            elementsInRangeK1K2(root.left, k1, k2);
            System.out.print(root.data + " ");
            elementsInRangeK1K2(root.right, k1, k2);
        } else if (root.data < k1) {
            elementsInRangeK1K2(root.right, k1, k2);
        } else if (root.data > k2) {
            elementsInRangeK1K2(root.left, k1, k2);
        }
    }
}