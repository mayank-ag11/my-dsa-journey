/***
 * Given a BST and an integer k. Find and return the path from the node with data k and root (if a node with data k is present in given BST) in a list. Return empty list otherwise.
 * Note: Assume that BST contains all unique elements.
 ***/
vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	if(root == NULL)
        return NULL;
    
    if(root->data == data) {
        vector<int> *ans = new vector<int>();
        ans->push_back(root->data);
        return ans;
    }
    vector<int> *ans = NULL;
    if(data < root->data)
        ans = getPath(root->left, data);
        
    else
        ans = getPath(root->right, data);
    
    if(ans != NULL)
        ans->push_back(root->data);
    
    return ans;
}