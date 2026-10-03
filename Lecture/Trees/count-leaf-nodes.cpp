// Given a generic tree, count and return the number of leaf nodes present in the given tree.
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
int numLeafNodes(TreeNode<int>* root) {
    if(root == NULL)
        return 0;
    if(root->numChildren() == 0)
        return 1;
    
    int ans = 0;
    for(int i = 0; i < root->numChildren(); i++) {
        ans += numLeafNodes(root->getChild(i));
    }
    return ans;
}