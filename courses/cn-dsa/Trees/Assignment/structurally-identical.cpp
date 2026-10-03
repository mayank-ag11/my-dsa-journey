// Given two Generic trees, return true if they are structurally identical i.e. they are made of nodes with the same values arranged in the same way.

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
bool isIdentical(TreeNode<int> *root1, TreeNode<int> *root2) {
	if(root1 == NULL and root2 == NULL)
        return true;

    if(root1 == NULL or root2 == NULL)
        return false;
    
    if(root1->data != root2->data)
        return false;
    
    if(root1->numChildren() != root2->numChildren())
        return false;
    
    for(int i = 0; i < root1->numChildren(); i++) {
        bool ans = isIdentical(root1->getChild(i), root2->getChild(i));
        if(ans == false)
            return false;
    }
    return true;
}