/***
 * Given the binary Tree and two nodes say ‘p’ and ‘q’. Determine whether the two nodes are cousins of each other or not.
 * Two nodes are said to be cousins of each other if they are at same level of the Binary Tree and have different parents.
 * Do it in O(n).
 ***/
// Better way, need not to use variable 'd' to get depth
// first => depth and second => parent node
pair<int, BinaryTreeNode<int> *> *depthAndParent(BinaryTreeNode<int> *root, int x, 
                                                BinaryTreeNode<int> *parent) {    
    if(root == NULL)
        return NULL;
    
    pair<int, BinaryTreeNode<int> *> *p = NULL;
    
    if(root->data == x) {
        p = new pair<int, BinaryTreeNode<int> *>();
        p->first = 0;
        p->second = parent;
        return p;
    }
    // Search for x in left subtree, return if found
    p = depthAndParent(root->left, x, root);
    if(p != NULL) {
        p->first = p->first + 1;
        return p;
    }
    
    // If not found, then search it in right subtree
    p = depthAndParent(root->right, x, root);
    if(p != NULL)
    	p->first = p->first + 1;
    return p;
}

bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
    if(root == NULL)
        return true;
    
    pair<int, BinaryTreeNode<int> *> *pair_p = depthAndParent(root, p, NULL);
    pair<int, BinaryTreeNode<int> *> *pair_q = depthAndParent(root, q, NULL);
    
    if(pair_p->first == pair_q->first and pair_p->second !=  pair_q->second)
        return true;
    return false;
}

// First Try
// first => depth and second => parent node
pair<int, BinaryTreeNode<int> *> *depthAndParent(BinaryTreeNode<int> *root, int x, 
                                                BinaryTreeNode<int> *parent, int d) {    
    if(root == NULL)
        return NULL;
    
    pair<int, BinaryTreeNode<int> *> *p = NULL;
    
    if(root->data == x) {
        p = new pair<int, BinaryTreeNode<int> *>();
        p->first = d;
        p->second = parent;
        return p;
    }
    // Search for x in left subtree, return if found
    p = depthAndParent(root->left, x, root, d + 1);
    if(p != NULL)
        return p;
    
    // If not found, then search it in right subtree
    p = depthAndParent(root->right, x, root, d + 1);
    return p;
}

bool isCousin(BinaryTreeNode<int> *root, int p, int q) {
    if(root == NULL)
        return true;
    
    pair<int, BinaryTreeNode<int> *> *pair_p = depthAndParent(root, p, NULL, 1);
    pair<int, BinaryTreeNode<int> *> *pair_q = depthAndParent(root, q, NULL, 1);
    
    if(pair_p->first == pair_q->first and pair_p->second !=  pair_q->second)
        return true;
    return false;
}