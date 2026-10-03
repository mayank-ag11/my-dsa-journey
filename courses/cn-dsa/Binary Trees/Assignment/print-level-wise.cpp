/***
 * For a given a Binary Tree of type integer, print it in a level order fashion where each level will be printed on a new line. Elements on every level will be printed in a linear fashion and a single space will separate them.
 * Test Case:
        Input: 10 20 30 40 50 -1 60 -1 -1 -1 -1 -1 -1 
        Output: 10
                20 30
                40 50 60
 ***/
void printLevelWise(BinaryTreeNode<int> *root) {
    if(root == NULL)
        return;
    
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()) {
        BinaryTreeNode<int> *front = q.front();
        q.pop();
        
        if(front == NULL) {
            if(q.empty())
                break;
            cout << '\n';
            q.push(NULL);
            continue;
        }
        
        cout << front->data << ' ';
        
        if(front->left != NULL)
            q.push(front->left);
        if(front->right != NULL)
            q.push(front->right);
    }
}

// Java
/*
Time complexity: O(N)
Space complexity: O(N)
where N is the number of nodes in the input tree
*/
import java.util.LinkedList;
import java.util.Queue;
public class Solution {
    public static void printLevelWise(BinaryTreeNode<Integer> root) {
        Queue<BinaryTreeNode<Integer>> pendingNodes = new LinkedList<>();
        pendingNodes.add(root);
        pendingNodes.add(null);
        while (!pendingNodes.isEmpty()) {
            BinaryTreeNode<Integer> frontNode = pendingNodes.poll();
            if (frontNode == null) {
                System.out.println();
                if (!pendingNodes.isEmpty())
                    pendingNodes.add(null);
            }
            else {
                System.out.print(frontNode.data + " ");
                if (frontNode.left != null)
                    pendingNodes.add(frontNode.left);

                if (frontNode.right != null)
                    pendingNodes.add(frontNode.right);
            }
        }
    }
}