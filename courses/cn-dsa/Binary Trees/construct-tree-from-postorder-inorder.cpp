/***
 * For a given postorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.
 * Assume that the Binary Tree contains only unique elements.
 ***/
BinaryTreeNode<int>* buildTree(int *postorder, int *inorder, int postS, int postE, int inS, int inE) {
    // Base Case
    if(postS > postE or inS > inE)
        return NULL;
    
    // Root is the last element of postorder array
    int rootData = postorder[postE];
    
    // Searching the root in inorder array
    int rootIndex = -1;
    for(int i = inS; i <= inE; i++) {
        if(inorder[i] == rootData) {
            rootIndex = i;
            break;
        }
    }
    // Finding the indexes for the left and right
    int LinS = inS, LinE = rootIndex - 1;
    int LpostS = postS, LpostE = LinE - LinS + LpostS;
    int RinS = rootIndex + 1, RinE = inE;
    int RpostS = LpostE + 1, RpostE = postE - 1;
    
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = buildTree(postorder, inorder, LpostS, LpostE, LinS, LinE);
    root->right = buildTree(postorder, inorder, RpostS, RpostE, RinS, RinE);
    
    return root;
}

BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    return buildTree(postorder, inorder, 0, postLength - 1, 0, inLength - 1);
}