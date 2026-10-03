 /***
  * For a given Binary Tree of type integer, print all the nodes without any siblings.
  * Output Format:
    The only line of output prints the node data in a top to down fashion with reference to the root. 
    Node data in the left subtree will be printed first and then the right subtree.
    A single space will separate them all.
  ***/
void printNodesWithoutSibling(BinaryTreeNode<int> *root) {
    if(root == NULL)
        return;
    
    if(root->left and !root->right) {
        cout << root->left->data << ' ';
    }
    else if(root->right and !root->left) {
        cout << root->right->data << ' ';
    }
    
    printNodesWithoutSibling(root->left);
    printNodesWithoutSibling(root->right);
}