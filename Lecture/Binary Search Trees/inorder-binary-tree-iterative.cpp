// https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
#include <stack>
void inOrder(BinaryTreeNode<int>* root) {
	stack<BinaryTreeNode<int> *> st;
    BinaryTreeNode<int> *curr = root;

    while(curr != NULL or !st.empty()) {
        // Reach the left most node of the curr node
        while(curr != NULL) {
            st.push(curr);
            curr = curr->left;
        }

        curr = st.top();
        st.pop();

        cout << curr->data << ' ';

        // We have visited the node and it's left subtree. Now, it's right subtree's turn
        curr = curr->right;
    }
}