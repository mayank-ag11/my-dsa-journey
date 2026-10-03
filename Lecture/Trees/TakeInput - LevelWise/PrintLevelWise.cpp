void printLevelWise(TreeNode<int>* root) {
    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);
    
    while(pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << front->data << ':';
        
        int i = 0, n = front->children.size();
        for(i = 0; i < n - 1; i++) {
            cout << front->children[i]->data << ',';
            pendingNodes.push(front->children[i]);
        }
        
        if(i < n) {
            cout << front->children[i]->data;
            pendingNodes.push(front->children[i]);
        }
        cout << '\n';
    }
}