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
void postorder(TreeNode<int> *root) {
    if(root == NULL)
        return;

    for(int i = 0; i < root->children.size(); i++) {
        postorder(root->children[i]);
    }
    cout << root->data << ' ';
}