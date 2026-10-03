// Given a tree and an integer x, find and return number of Nodes which are greater than x.

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
int nodesGreaterThanX(TreeNode<int> *root, int x) {
    if(root == NULL)
        return 0;

    int ans = 0;
    if(root->data > x)
        ans = 1;
    
    for(int i = 0; i < root->numChildren(); i++) {
        ans += nodesGreaterThanX(root->getChild(i), x);
    }
    return ans;
}