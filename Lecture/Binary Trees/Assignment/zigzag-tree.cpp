/***
 * Given a binary tree, print the zig zag order. In zigzag order, level 1 is printed from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.
 * Test Case:
        Input: 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
        Output: 5
                10 6
                2 3
                9
 ***/
// See ZigZagTree.java for a better approach using stack
#include <vector>
void zigZagOrder(BinaryTreeNode<int> *root) {
    if(root == NULL)
        return;
    
    bool odd = true;
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    vector<int> v;
    
    while(!q.empty()) {
        BinaryTreeNode<int>* front = q.front();
        q.pop();
        
        if(front == NULL) {
            if(odd) {
                for(int i = 0; i < v.size(); i++)
                    cout << v[i] << ' ';
            }
            else {
                for(int i = v.size() - 1; i >= 0; i--)
                    cout << v[i] << ' ';
            }
            if(q.empty())
                break;
            
            cout << '\n';
            odd = !odd;
            v.clear();
            q.push(NULL);
            continue;
        }
        
        v.push_back(front->data);
        
        if(front->left != NULL)
            q.push(front->left);
        if(front->right != NULL)
            q.push(front->right);
    }
}