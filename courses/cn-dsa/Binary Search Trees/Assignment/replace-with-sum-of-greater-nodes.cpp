/***
 * Given a binary search tree, you have to replace each node's data with the sum of all nodes which are greater or equal than it. You need to include the current node's data also.
 * That is, if in given BST there is a node with data 5, you need to replace it with sum of its data (i.e. 5) and all nodes whose data is greater than or equal to 5.
 * Note: You don't need to return or print, just change the data of each node.
 * Test case: 8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
 * Output (printed in level order form): 
        18 
        36 10 
        38 31 
        25
 ***/
// Better way
int replaceWithLargerNodesSum(BinaryTreeNode<int> *root, int sum) {
    if(root == NULL)
        return sum;
    
    sum = replaceWithLargerNodesSum(root->right, sum);
    
    sum += root->data;
    root->data = sum;
    
    sum = replaceWithLargerNodesSum(root->left, sum);
    
    return sum;
}
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    replaceWithLargerNodesSum(root, 0);
}

// First Try
int getSum(BinaryTreeNode<int>* root) {
    if(root == NULL)
        return 0;
    return root->data + getSum(root->left) + getSum(root->right);
}
int replaceWithLargerNodesSum(BinaryTreeNode<int> *root, int sum) {
    if(root == NULL)
        return sum;
    
    sum = replaceWithLargerNodesSum(root->left, sum);
    
    int x = root->data;
    root->data = sum;
    sum -= x;
    
    sum = replaceWithLargerNodesSum(root->right, sum);
    
    return sum;
}
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root) {
    int sum = getSum(root);
    replaceWithLargerNodesSum(root, sum);
}