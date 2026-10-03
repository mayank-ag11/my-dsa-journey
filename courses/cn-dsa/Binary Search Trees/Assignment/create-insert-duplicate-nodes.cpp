/***
 * For a given a Binary Tree of type integer, duplicate every node of the tree and attach it to the left of itself.
 * The root will remain the same. So you just need to insert nodes in the given Binary Tree.
 * 
 * Input: https://files.codingninjas.in/seventypercent-4796.png
 * Output: https://files.codingninjas.in/bt-2-page-2-4794.png
 ***/
/************************************************************
    Following is the Binary Tree node structure
    template <typename T>
    class BinaryTreeNode
    {
        public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data)
        {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
************************************************************/
void insertDuplicateNode(BinaryTreeNode<int> *root) {
    if(root == NULL)
        return;
    
    insertDuplicateNode(root->left);
    insertDuplicateNode(root->right);
    
    BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(root->data);
    newNode->left = root->left;
    root->left = newNode;
}