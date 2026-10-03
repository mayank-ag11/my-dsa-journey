/***
 * Given a generic tree and an integer n. Find and return the node with next larger element in the tree i.e. find a node with value just greater than n.
 * Return NULL if no node is present with the value greater than n.
 ***/

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
TreeNode<int>* nextLargerElement(TreeNode<int> *root, int n) {
    if(root == NULL)
        return NULL;
    
    TreeNode<int> *ans = NULL;
    if(root->data > n)
        ans = root;
    
    for(int i = 0; i < root->numChildren(); i++) {
        TreeNode<int> *temp = nextLargerElement(root->getChild(i), n);
        if(temp != NULL) {
            if(ans == NULL or temp->data < ans->data)
                ans = temp;
        }
    }
    return ans;
}