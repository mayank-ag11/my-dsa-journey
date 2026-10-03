/************************************************************
    Following is the structure for the TreeNode class

    template <typename T>
    class TreeNode {
     public:
        T data;
        vector<TreeNode<T>*> children;
    
        TreeNode(T data) {
            this->data = data;
        }
    
        ~TreeNode() {
            for (int i = 0; i < children.size(); i++) {
                delete children[i];
            }
        }
    };
************************************************************/
int getHeight(TreeNode<int>* root) {
    if(root == NULL)
        return 0;
    
    int height = 0;
    for(int i = 0; i < root->children.size(); i++) {
        int childHeight = getHeight(root->children[i]);
        if(childHeight > height)
            height = childHeight;
    }
    return height + 1;
}