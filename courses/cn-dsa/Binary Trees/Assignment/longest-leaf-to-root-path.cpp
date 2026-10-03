/***
 * Given a binary tree, return the longest path from leaf to root. Longest means, a path which contain maximum number of nodes from leaf to root.
 * Testcase: 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
 * Output: 9 3 6 5
 ***/
vector<int>* longestPath(BinaryTreeNode<int>* root) {
	if(root == NULL)
        return NULL;
    
    if(root->left == NULL and root->right == NULL) {
        vector<int> *output = new vector<int>();
        output->push_back(root->data);
		return output;
    }
    
    vector<int> *leftOutput = longestPath(root->left);
    vector<int> *rightOutput = longestPath(root->right);
    
    vector<int> *output;
    if(leftOutput != NULL and rightOutput != NULL)
        output = (leftOutput->size() >= rightOutput->size()) ? leftOutput : rightOutput;
    
    else
        output = (leftOutput != NULL) ? leftOutput : rightOutput;

    output->push_back(root->data);
    return output;
}