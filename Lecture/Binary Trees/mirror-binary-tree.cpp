/***
 * For a given Binary Tree of type integer, update it with its corresponding mirror image.
 * https://ninjasfiles.s3.amazonaws.com/0000000000000485.png
 ***/
/**********************************************************
	Following is the Binary Tree Node class structure

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
void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    if(root == NULL)
        return;
    
    BinaryTreeNode<int> *temp = root->left;
    root->left = root->right;
    root->right = temp;
    
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);
}

// Java
/*
Time complexity: O(N)
Space complexity: O(H)
Where N is the number of nodes in the input tree
and H is the height of the input tree
*/
public class Solution {
    public static void mirrorBinaryTree(BinaryTreeNode<Integer> root){
        if(root == null)
            return;
        mirrorBinaryTree(root.left);
        mirrorBinaryTree(root.right);
        
        BinaryTreeNode<Integer> templeft = root.left;
        root.left = root.right;
        root.right = templeft;
    }
}