/***
 * Implement the BST class which includes following functions -
 *  1. search
    Given an element, find if that is present in BST or not. Return true or false.
 *  2. insert -
    Given an element, insert that element in the BST at the correct position. If element is equal to the data of the node, insert it in the left subtree.
 *  3. delete -
    Given an element, remove that element from the BST. If the element which is to be deleted has both children, replace that with the minimum element from right sub-tree.
 *  4. printTree (recursive) -
    Print the BST in ithe following format -
        For printing a node with data N, you need to follow the exact format -
            N:L:x,R:y
        where, N is data of any node present in the binary tree. x and y are the values of left and right child of node N. Print the children only if it is not null.
        There is no space in between.
        You need to print all nodes in the recursive format in different lines.
 ***/
/**********************************************************
	Following is the Binary Tree Node class structure
	template <typename T>
	class BinaryTreeNode {
    	public: 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this->data = data;
        	left = NULL;
        	right = NULL;
    	}
	};
***********************************************************/
#include<climits>
class BST {
    BinaryTreeNode<int> *root;
    
    bool search(BinaryTreeNode<int> *root, int data) {
        if(root == NULL)
            return false;
        if(root->data == data)
            return true;
        else if(root->data > data)
            return search(root->left, data);
        else
            return search(root->right, data);
    }
    
    BinaryTreeNode<int>* insert(BinaryTreeNode<int> *root, int data) {
        if(root == NULL) {
            BinaryTreeNode<int> *newNode = new BinaryTreeNode<int>(data);
            return newNode;
        }
        
        if(root->data >= data)
            root->left = insert(root->left, data);
        else
            root->right = insert(root->right, data);
        return root;
    }
    
    void print(BinaryTreeNode<int> *root) {
        if(root == NULL)
            return;
        
        cout << root->data << ':';
        if(root->left != NULL)
            cout << "L:" << root->left->data << ',';
        
        if(root->right != NULL)
            cout << "R:" << root->right->data;
        cout << '\n';
        
        print(root->left);
        print(root->right);
    }
    
    int minimum(BinaryTreeNode<int> *root) {
        if(root == NULL)
            return INT_MAX;
        
        return min(root->data, minimum(root->left));
    }
    
    BinaryTreeNode<int>* remove(BinaryTreeNode<int> *root, int data) {
        if(root == NULL)
            return NULL;
        if(root->data == data) {
            if(root->left == NULL) {
                BinaryTreeNode<int> *temp = root->right;
                root->right = NULL;
                delete root;
                return temp;
            }
            else if(root->right == NULL) {
                BinaryTreeNode<int> *temp = root->left;
                root->left = NULL;
                delete root;
                return temp;
            }
            else {
                // My original approach
                // int rightMin = minimum(root->right);

                // Better approach
                BinaryTreeNode<int> *minNode = root->right;
                while(minNode->left != NULL)
                    minNode = minNode->left;
                
                int rightMin = minNode->data;

                root->data = rightMin;
                root->right = remove(root->right, rightMin);
                return root;
            }
        }
        else if(root->data > data) {
            root->left = remove(root->left, data);
            return root;
        }
        else {
            root->right = remove(root->right, data);
            return root;
        }
    }
    
   public:
    BST() { 
        root = NULL;
    }

    ~BST() {
        delete root;
    }

	/*----------------- Public Functions of BST -----------------*/

    void remove(int data) { 
        root = remove(root, data); 
    }

    void print() { 
        print(root);
    }

    void insert(int data) { 
        root = insert(root, data); 
    }

    bool search(int data) {
		return search(root, data); 
    }
};