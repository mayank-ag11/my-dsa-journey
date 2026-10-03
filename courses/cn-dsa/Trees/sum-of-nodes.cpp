// Following is the given Tree node structure.
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

int sumOfNodes(TreeNode<int>* root) {
    if(root == NULL)
        return 0;

    int ans = root->data;
    for(int i = 0; i < root->numChildren(); i++) {
        ans += sumOfNodes(root->getChild(i));
    }
    return ans;
}