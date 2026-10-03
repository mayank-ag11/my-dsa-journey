/***
 * Given a binary tree, write code to create a separate linked list for each level. You need to return the array which contains head of each level linked list.
 ***/
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

/*
Time complexity: O(N)
Space complexity: O(H)
where N is the number of nodes in the input BST
and H is the height of the input BST
*/
public class LevelWiseLinkedList {
    public static ArrayList<LinkedListNode<Integer>> constructLinkedListForEachLevel(BinaryTreeNode<Integer> root) {
        if (root == null) {
            return null;
        }
        Queue<BinaryTreeNode<Integer>> pendingNodes = new LinkedList<BinaryTreeNode<Integer>>();
        pendingNodes.add(root);
        int currentLevelRemaining = 1;
        int nextLevelCount = 0;
        LinkedListNode<Integer> currentLevelHead = null;
        LinkedListNode<Integer> currentLevelTail = null;
        ArrayList<LinkedListNode<Integer>> output = new ArrayList<>();
        while (!pendingNodes.isEmpty()) {
            BinaryTreeNode<Integer> currentNode;
            currentNode = pendingNodes.remove();
            LinkedListNode<Integer> newNode = new LinkedListNode<Integer>(currentNode.data);
            if (currentLevelHead == null) {
                currentLevelHead = newNode;
                currentLevelTail = newNode;
            } else {
                currentLevelTail.next = newNode;
                currentLevelTail = newNode;
            }
            if (currentNode.left != null) {
                pendingNodes.add(currentNode.left);
                nextLevelCount++;
            }
            if (currentNode.right != null) {
                pendingNodes.add(currentNode.right);
                nextLevelCount++;
            }
            currentLevelRemaining--;
            if (currentLevelRemaining == 0) {
                output.add(currentLevelHead);
                currentLevelHead = null;
                currentLevelTail = null;
                currentLevelRemaining = nextLevelCount;
                nextLevelCount = 0;
            }
        }
        return output;
    }
}