/***
 * In a given Generic Tree, replace each node with its depth value. You need to just update the data of each node, no need to return or print anything.
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
void replaceWithDepthValue(TreeNode<int> *root, int depth) {
    root->data = depth;
    for(int i = 0; i < root->numChildren(); i++)
        replaceWithDepthValue(root->getChild(i), depth + 1);
}
void replaceWithDepthValue(TreeNode<int> *root){    
	if(root == NULL)
        return;
    replaceWithDepthValue(root, 0);
}