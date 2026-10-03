// Print all the nodes which are at level/depth K

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
void printAtLevelK(TreeNode<int>* root, int k) {
    if(root == NULL)
        return 0;
    if(k == 0) {
        cout << root->data << endl;
        return;
    }

    for(int i = 0; i < root->children.size(); i++) {
        printAtLevelK(root->children[i], k - 1);
    }
}