/***
 * Given a binary tree, check if it is balanced. Return true if given binary tree is balanced, false otherwise.
 * A empty binary tree or binary tree with zero nodes is always balanced. For a non empty binary tree to be balanced, following conditions must be met:
    1. The left and right subtrees must be balanced.
    2. |hL - hR| <= 1, where hL is the height or depth of left subtree and hR is the height or depth of right subtree.
 ***/
// returns a pair: if tree is balanced or not and it's height
pair<bool, int> isBalancedHelper(BinaryTreeNode<int> *root) {
    pair<bool, int> p;
    if(root == NULL) {
        p.first = true;
        p.second = 0;
        return p;
    }
    
    pair<bool, int> lp = isBalancedHelper(root->left);
    pair<bool, int> rp = isBalancedHelper(root->right);
    
    bool isBalanced = lp.first and rp.first;
    int height = 1 + max(lp.second, rp.second);
    
    if(abs(lp.second - rp.second) > 1)
        isBalanced = false;
    
    p.first = isBalanced;
    p.second = height;
    return p;
}

bool isBalanced(BinaryTreeNode<int> *root) {
	return isBalancedHelper(root).first;
}