/***
 * For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.
 * Assume that the Binary Tree contains only unique elements.
 ***/
BinaryTreeNode<int>* buildTree(int *preorder, int *inorder, int preS, int preE, int inS, int inE) {
    // Base Case
    if(preS > preE or inS > inE)
        return NULL;
    
    // Root is the first element of preorder array
    int rootData = preorder[preS];
    
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
    int LpreS = preS + 1, LpreE = LinE - LinS + LpreS;
    int RinS = rootIndex + 1, RinE = inE;
    int RpreS = LpreE + 1, RpreE = preE;
    
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    root->left = buildTree(preorder, inorder, LpreS, LpreE, LinS, LinE);
    root->right = buildTree(preorder, inorder, RpreS, RpreE, RinS, RinE);
    
    return root;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    return buildTree(preorder, inorder, 0, preLength - 1, 0, inLength - 1);
}