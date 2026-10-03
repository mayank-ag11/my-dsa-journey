/***
 * Given a sorted integer array A of size n, which contains all unique elements. You need to construct a balanced BST from this input array. Return the root of constructed BST.
 * If array size is even, take first mid as root.
 ***/
BinaryTreeNode<int>* constructTree(int *input, int l, int r) {
    if(l > r)
        return NULL;
    
    int mid = l + (r - l) / 2;
    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(input[mid]);
    root->left = constructTree(input, l, mid - 1);
    root->right = constructTree(input, mid + 1, r);
    return root;
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
	return constructTree(input, 0, n - 1);
}