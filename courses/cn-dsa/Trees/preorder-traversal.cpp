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
void preorder(TreeNode<int> *root) {
    if(root == NULL)
        return;

    cout << root->data << ' ';
    for(int i = 0; i < root->children.size(); i++) {
        preorder(root->children[i]);
    }
}