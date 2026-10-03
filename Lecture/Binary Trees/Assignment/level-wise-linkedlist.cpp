/***
 * Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.
 ***/
/**********************************************************
	Following are the Binary Tree Node class structure and
	the Node class structure

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
	class Node {
		public:
    	T data;
    	Node<T> *next;
    	Node(T data) {
        	this->data=data;
        	this->next=NULL;
    	}
	};

***********************************************************/
vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {  
    vector<Node<int>*> v;
    if(root == NULL)
        return v;
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    
    Node<int> *head = NULL;
    Node<int> *tail = NULL;
    while(!q.empty()) {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        
        if(front == NULL) {
            v.push_back(head);
            head = NULL;
            tail = NULL;
            
            if(q.empty())
                break;
            q.push(NULL);
            continue;
        }
        
    	Node<int> *node = new Node<int>(front->data);
        if(head == NULL) {
            head = node;
            tail = node;
        }
        else {
            tail->next = node;
            tail = tail->next;
        }
        
        if(front->left != NULL)
            q.push(front->left);
        if(front->right != NULL)
            q.push(front->right);
    }
    return v;
}