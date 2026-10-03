/***
 * For a given a Binary Tree of type integer, find and return the minimum and the maximum data values.
 * Return the output as an object of Pair class, which is already created.
 ***/
/*
	The first value of the pair must be the minimum value in the tree and 
	the second value of the pair must be the maximum value in the tree
*/
#include <climits>
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
    pair<int, int> p;
	if(root == NULL) {
        p.first = INT_MAX;
        p.second = INT_MIN;
        return p;
    }
    
    int mini, maxi;
    mini = maxi = root->data;
    
    pair<int, int> lp = getMinAndMax(root->left);
    pair<int, int> rp = getMinAndMax(root->right);
    
    mini = min(mini, min(lp.first, rp.first));
    maxi = max(maxi, max(lp.second, rp.second));
    
    p.first = mini;
    p.second = maxi;
    return p;
}