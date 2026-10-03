/***
 * Given a binary tree, remove all leaf nodes from it. Leaf nodes are those nodes, which don't have any children.
 * Note:
   1. Root will also be a leaf node if it doesn't have left and right child. 
   2. You don't need to print the tree, just remove all leaf nodes and return the updated root.
 ***/
BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {
    if(root == NULL)
        return NULL;
    
    if(root->left == NULL and root->right == NULL)
        return NULL;
    
    root->left = removeLeafNodes(root->left);
    root->right = removeLeafNodes(root->right);
    
    return root;
}