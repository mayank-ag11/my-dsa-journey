/***
 * Given a binary search tree and data of two nodes, find 'LCA' (Lowest Common Ancestor) of the given two nodes in the BST.
 * LCA of two nodes A and B is the lowest or deepest node which has both A and B as its descendants.
 * Eg: https://files.codingninjas.in/image1-5333.jpg
 * 
 * Note: It is defined that each node is a descendant to itself, so, if there are two nodes X and Y and X has a direct connection from Y, then Y is the lowest common ancestor.
 * Eg: https://files.codingninjas.in/image2-5334.jpg
 * 
 * Note: 1. If out of 2 nodes only one node is present, return that node. 
         2. If both are not present, return -1.
 ***/

BinaryTreeNode<int> *getLCAHelper(BinaryTreeNode <int>* root , int a, int b) { 
    if(root == NULL or root->data == a or root->data == b)
    	return root;
    
    if(root->data > a and root->data > b)
        return getLCAHelper(root->left, a, b);
    
    if(root->data < a and root->data < b)
        return getLCAHelper(root->right, a, b);
    
    BinaryTreeNode<int> *left = getLCAHelper(root->left, a, b);
    BinaryTreeNode<int> *right = getLCAHelper(root->right, a, b);
    
    if(left and right)
        return root;
    if(left)
        return left;
    
    return right;
}
int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    BinaryTreeNode<int> *node = getLCAHelper(root, a, b);
    if(node == NULL)
        return -1;
    else
        return node->data;
}