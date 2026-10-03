
/***
 * Given a binary tree, print the zig zag order. In zigzag order, level 1 is printed from left to right, level 2 from right to left and so on. This means odd levels should get printed from left to right and even level right to left.
 * Test Case:
        Input: 5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
        Output: 5
                10 6
                2 3
                9
 ***/
/*
Time complexity: O(N)
Space complexity: O(H)
where N is the number of nodes in the input tree
and H is the height of the input tree
*/
import java.util.ArrayList;
import java.util.Stack;

public class ZigZagTree {
    public static void printZigZag(BinaryTreeNode<Integer> root) {
        if (root == null) {
            return;
        }
        QueueUsingLL<BinaryTreeNode<Integer>> queue = new QueueUsingLL<>();
        Stack<BinaryTreeNode<Integer>> stack = new Stack<>();
        int level = 1;
        queue.enqueue(root);
        while (!queue.isEmpty()) {
            BinaryTreeNode<Integer> currentNode;
            try {
                currentNode = queue.dequeue();
                System.out.print(currentNode.data + " ");
                if (level % 2 == 0) {
                    if (currentNode.right != null)
                        stack.push(currentNode.right);
                    if (currentNode.left != null)
                        stack.push(currentNode.left);
                } else {
                    if (currentNode.left != null)
                        stack.push(currentNode.left);
                    if (currentNode.right != null)
                        stack.push(currentNode.right);
                }
                if (queue.isEmpty()) {
                    while (!stack.isEmpty()) {
                        queue.enqueue(stack.pop());
                    }
                    System.out.println();
                    level++;
                }
            } catch (QueueEmptyException e) {
            }
        }
    }
}