/***
 * You are given a Binary Tree of type integer, a target node, and an integer value K.
 * Print the data of all nodes that have a distance K from the target node. The order in which they would be printed will not matter.
 * Test case: https://files.codingninjas.in/node-distance-from-k-4809.png
 * For a given input tree(refer to the image above):
    1. Target Node: 5
    2. K = 2
 * Output: Starting from the target node 5, the nodes at distance K are 7 4 and 1.
 * Help: https://www.geeksforgeeks.org/print-nodes-distance-k-given-node-binary-tree/
 ***/

/* Recursive function to print all the nodes at distance k in the
   tree (or subtree) rooted with given root. See  */
void printNodesAtDistanceKDown(BinaryTreeNode<int> *root, int k) {
    if(root == NULL or k < 0)
        return;
    // If we reach a k distant node, print it
    if(k == 0) {
        cout << root->data << '\n';
        return;
    }
    printNodesAtDistanceKDown(root->left, k-1);
    printNodesAtDistanceKDown(root->right, k-1);
}

// Prints all nodes at distance k from a given target node.
// The k distant nodes may be upward or downward.  This function
// Returns distance of root from target node, it returns -1 if target
// node is not present in tree rooted with root.
int nodesAtDistanceKHelper(BinaryTreeNode<int> *root, int target, int k) {
    // Base Case: If tree is empty, return -1
    if(root == NULL)
        return -1;
    
    // If target is same as root. Use the downward function
    // to print all nodes at distance k in subtree rooted with
    // target or root
    if(root->data == target) {
        printNodesAtDistanceKDown(root, k);
        return 0;
    }
    
    // Recur for left subtree
    int dl = nodesAtDistanceKHelper(root->left, target, k);
    
    // Check if target node was found in left subtree
    if(dl != -1) {
        // If root is at distance k from target, print root
        // Note that dl is Distance of root's left child from target
        if(dl + 1 == k)
            cout << root->data << '\n';
        // Else go to right subtree and print all k-dl-2 distant nodes
        // Note that the right child is 2 edges away from left child
        else
            printNodesAtDistanceKDown(root->right, k-dl-2);
        
        // Add 1 to the distance and return value for parent calls
        return 1 + dl;
    }
    
    // MIRROR OF ABOVE CODE FOR RIGHT SUBTREE
    // Note that we reach here only when node was not found in left subtree
    int dr = nodesAtDistanceKHelper(root->right, target, k);
    if(dr != -1) {
        if(dr + 1 == k)
            cout << root->data << '\n';
        else
            printNodesAtDistanceKDown(root->left, k-dr-2);
        
        return 1 + dr;
    }
    
    // If target was neither present in left nor in right subtree
    return -1;
}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k) {
    nodesAtDistanceKHelper(root, node, k);
}