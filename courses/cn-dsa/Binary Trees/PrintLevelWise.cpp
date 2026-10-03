/***
 * For a given a Binary Tree of type integer, print the complete information of every node, when traversed in a level-order fashion.
 * To print the information of a node with data D, you need to follow the exact format :

           D:L:X,R:Y

    Where D is the data of a node present in the binary tree. 
    X and Y are the values of the left(L) and right(R) child of the node.
    Print -1 if the child doesn't exist.
 ***/
/**********************************************************
	Following is the Binary Tree Node class structure
	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
***********************************************************/
void printLevelWise(BinaryTreeNode<int> *root) {
	if(root == NULL)
        return;
    
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    
    while(pendingNodes.size() != 0) {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ":L:";
        
        if(front->left) {
            cout << front->left->data;
            pendingNodes.push(front->left);
        }
        else
            cout << "-1";
        
        cout << ",R:";
        
        if(front->right) {
            cout << front->right->data;
            pendingNodes.push(front->right);
        }
        else
            cout << "-1";
        cout << '\n';
    }
}