/***
 * Given a generic tree, print the input tree in level wise order. That is, print the elements at same level in one line (separated by space). Print different levels in differnet lines.
 * Test Case:
        Input: 10 3 20 30 40 2 40 50 0 0 0 0
        Output: 10
                20 30 40
                40 50
 ***/
// Following is the given Tree node structure.
/**************
class TreeNode {
	TreeNode<T>** children;
	int childCount;

	public:
	T data;

	TreeNode(T data);	// Constructor
	int numChildren();
	void addChild(TreeNode<T>* child);
	TreeNode<T>* getChild(int index);
	void setChild(int index, TreeNode<T>* child);
};
***************/

void printLevelWise(TreeNode<int>* root) {
    Queue<TreeNode<int>*> q;
    q.enqueue(root);
    q.enqueue(NULL);
    
    cout << root->data << '\n';
    
    while(!q.isEmpty()) {     
        TreeNode<int> *front = q.front();
        q.dequeue();
        
        if(front == NULL) {
            if(q.isEmpty())
                break;
            cout << '\n';
            q.enqueue(NULL);
            continue;
        }        
        // cout << front->data;
        
        // if(q.front() != NULL)
        //     cout << ' ';
        
        int n = front->numChildren();
        for(int i = 0; i < n; i++) {
            cout << front->getChild(i)->data << ' ';
            q.enqueue(front->getChild(i));
        }
    }
}