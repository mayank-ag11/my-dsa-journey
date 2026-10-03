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
/*
Time complexity: O(N)
Space complexity: O(H)
where N is the number of nodes in the input binary tree and
H is the height of the input binary tree
*/
public class PrintNodesAtKDistance {
    private static int nodesAtDistanceKHelper(BinaryTreeNode < Integer > root, int target, int k) {
        if (root == null) {
            return -1;
        }
        if (root.data == target) {
            nodesAtDistanceKDown(root, k);
            return 0;
        }
        int leftD = nodesAtDistanceKHelper(root.left, target, k);
        if (leftD != -1) {
            if (leftD + 1 == k) {
                System.out.println(root.data);
            } else {
                nodesAtDistanceKDown(root.right, k - leftD - 2);
            }
            return 1 + leftD;
        }
        int rightD = nodesAtDistanceKHelper(root.right, target, k);
        if (rightD != -1) {
            if (rightD + 1 == k) {
                System.out.println(root.data);
            } else {
                nodesAtDistanceKDown(root.left, k - rightD - 2);
            }
            return 1 + rightD;
        }
        return -1;
    }
    private static void nodesAtDistanceKDown(BinaryTreeNode < Integer > root, int k) {
        if (root == null) {
            return;
        }
        if (k == 0) {
            System.out.println(root.data);
            return;
        }
        nodesAtDistanceKDown(root.left, k - 1);
        nodesAtDistanceKDown(root.right, k - 1);
    }
    public static void nodesAtDistanceK(BinaryTreeNode < Integer > root, int node, int k) {
        nodesAtDistanceKHelper(root, node, k);
    }
}
