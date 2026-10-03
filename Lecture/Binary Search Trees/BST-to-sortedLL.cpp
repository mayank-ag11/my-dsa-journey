/***
 * Given a BST, convert it into a sorted linked list. You have to return the head of LL.
 ***/
/**********************************************************
	Following are the Binary Tree Node class structure and the 
	Node class structure

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

	template <typename T>
 	class Node{
    	public:
    	T data;
    	Node<T> *next;
    
    	Node(T data) {
        	this->data = data;
        	this->next = NULL;
    	}
 	};
***********************************************************/
class LLPair {
    public:
    Node<int> *head;
    Node<int> *tail;
    
    LLPair() {
        head = tail = NULL;
    }
};

LLPair constructLinkedListHelper(BinaryTreeNode<int>* root) {
    LLPair p;
    if(root == NULL)
        return p;
    
    LLPair lp = constructLinkedListHelper(root->left);
    LLPair rp = constructLinkedListHelper(root->right);
    
    Node<int> *newNode = new Node<int>(root->data);
    if(lp.head == NULL) {
        p.head = newNode;
    }
    else {
        p.head = lp.head;
        lp.tail->next = newNode;
    }
    if(rp.head == NULL) {
        p.tail = newNode;
    }
    else {
        newNode->next = rp.head;
    	p.tail = rp.tail;
    }
    return p;
}

Node<int>* constructLinkedList(BinaryTreeNode<int>* root) {
	return constructLinkedListHelper(root).head;
}