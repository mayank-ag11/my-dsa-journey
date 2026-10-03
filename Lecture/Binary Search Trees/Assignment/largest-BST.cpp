/***
 * Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.
 ***/
#include<climits>
class BstSubtree {
    public:
    int max, min, height;
    bool isBST;
    
    BstSubtree() {
        max = INT_MIN;
        min = INT_MAX;
        height = 0;
        isBST = true;
    }
};
BstSubtree largestBSTSubtreeFinder(BinaryTreeNode<int> *root) {
    BstSubtree b;
    if(root == NULL)
        return b;
    
    BstSubtree lb = largestBSTSubtreeFinder(root->left);
    BstSubtree rb = largestBSTSubtreeFinder(root->right);
    
    if(lb.isBST == false or rb.isBST == false)
        b.isBST = false;
    if(lb.max > root->data or rb.min < root->data)
        b.isBST = false;
    
    if(b.isBST) {
        b.max = max(root->data, rb.max);
        b.min = min(root->data, lb.min);
        b.height = 1 + max(lb.height, rb.height);
    }
    else {
        b.max = max(root->data, max(lb.max, rb.max));
        b.min = min(root->data, min(lb.min, rb.min));
        b.height = max(lb.height, rb.height);
    }
    return b;
}
int largestBSTSubtree(BinaryTreeNode<int> *root) {
    return largestBSTSubtreeFinder(root).height;
}

/* First Try
Failed on test case: 5 3 6 2 4 -1 -1 -1 -1 -1 9 -1 -1
Expected output: 3, My output: 4
*/
pair<bool, int> largestBSTSubtreeFinder(BinaryTreeNode<int> *root) {
    // first -> isBST, second -> max BST height
    pair<bool, int> p;
    if(root == NULL) {
        p.first = true;
        p.second = 0;
        return p;
    }
    
    pair<bool, int> lp = largestBSTSubtreeFinder(root->left);
    pair<bool, int> rp = largestBSTSubtreeFinder(root->right);
    
    if(lp.first and rp.first) {
        p.first = true;
        if(root->left != NULL and root->data < root->left->data)
            p.first = false;
        if(root->right != NULL and root->data > root->right->data)
            p.first = false;
        
        if(p.first)
            p.second = 1 + max(lp.second, rp.second);
        else
            p.second = max(lp.second, rp.second);
    }
    else {
        p.first = false;
        p.second = max(lp.second, rp.second);
    }
    return p;
}
int largestBSTSubtree(BinaryTreeNode<int> *root) {
    return largestBSTSubtreeFinder(root).second;
}