/***
 * Node having sum of children and node is max
 * Given a tree, find and return the node for which sum of data of all children and the node itself is maximum. In the sum, data of node itself and data of immediate children is to be taken.
 ***/
// Following is the given Tree node structure
/**************
class TreeNode {
	TreeNode<T>** children;
	int childCount;

	public:
	T data;

	TreeNode(T data);	// Constructor
	int numChildren();
	void addChild(TreeNode<T>* child);
	TreeNode<T>* getChild(int index);
	void setChild(int index, TreeNode<T>* child);
};
***************/
// My Solution
#include <utility>
pair<TreeNode<int> *, int>* maxSumNodePair(TreeNode<int> *root) {
    int sum = root->data;
    for(int i = 0; i < root->numChildren(); i++)
        sum += root->getChild(i)->data;
    
    pair<TreeNode<int>*, int> *p = new pair<TreeNode<int>*, int>();
    p->first = root;
    p->second = sum;
    
    for(int i = 0; i < root->numChildren(); i++) {
        pair<TreeNode<int>*, int> *temp = maxSumNodePair(root->getChild(i));
        if(temp->second > p->second) {
            delete p;
            p = temp;
        }
    }   
    return p;
}

TreeNode<int>* maxSumNode(TreeNode<int> *root){
    if(root == NULL)
        return NULL;
    
    pair<TreeNode<int> *, int> *p = maxSumNodePair(root);
    return p->first;
}

// Coding Ninjas Solution
/*
    Time complexity: O(N)
    Space complexity: O(H)
    where N is the number of nodes in the tree and
    H is the height/depth of the tree
*/
#include <climits>
template <typename T>
class MaxNodePair
{
public:
    TreeNode<T> *node;
    int sum;
};
MaxNodePair<int> *maxSumNodeHelper(TreeNode<int> *root) {
    if (root == NULL) {
        MaxNodePair<int> *pair = new MaxNodePair<int>();
        pair->node = NULL;
        pair->sum = INT_MIN;
        return pair;
    }

    int sum = root->data;
    for (int i = 0; i < root->children.size(); i++)
        sum += root->children[i]->data;

    MaxNodePair<int> *ans = new MaxNodePair<int>();
    ans->node = root;
    ans->sum = sum;

    for (int i = 0; i < root->children.size(); i++) {
        MaxNodePair<int> *childAns = maxSumNodeHelper(root->children[i]);
        if (childAns->sum > ans->sum)
            ans = childAns;
    }
    return ans;
}
TreeNode<int> *maxSumNode(TreeNode<int> *root) {
    return maxSumNodeHelper(root)->node;
}