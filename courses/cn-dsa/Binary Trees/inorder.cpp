void inOrder(BinaryTreeNode<int>* root) {
	if (root == NULL)
		return;
	// left, root, right
	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);
}