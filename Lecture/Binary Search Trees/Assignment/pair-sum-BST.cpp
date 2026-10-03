/***
 * Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. You can use extra space of the order of O(log n).
 * Note:
   1. Assume BST contains all unique elements.
   2. In a pair, print the smaller element first.
 * Help: https://www.geeksforgeeks.org/find-a-pair-with-given-sum-in-bst/
         https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
 ***/
// Time: O(n), Space: O(logn)
#include <stack>
void printNodesSumToS(BinaryTreeNode<int> *root, int sum) {
    stack<BinaryTreeNode<int> *> st1, st2;
    bool done1 = false, done2 = false;
    int val1 = 0, val2 = 0;
    BinaryTreeNode<int> *curr1 = root, *curr2 = root;

    while(1) {
        // Find next node in Normal Inorder Traversal
        while(done1 == false) {
            if(curr1 != NULL) {
                st1.push(curr1);
                curr1 = curr1->left;
            }
            else {
                if(st1.empty())
                    done1 = true;
                else {
                    curr1 = st1.top();
                    st1.pop();
                    val1 = curr1->data;
                    curr1 = curr1->right;
                    done1 = true;
                }
            }
        }
        // Find next node in Reverse Inorder Traversal
        // The difference between above and below loop is, in the loop below, right subtree is traversed before left subtree
        while(done2 == false) {
            if(curr2 != NULL) {
                st2.push(curr2);
                curr2 = curr2->right;
            }
            else {
                if(st2.empty())
                    done2 = true;
                else {
                    curr2 = st2.top();
                    st2.pop();
                    val2 = curr2->data;
                    curr2 = curr2->left;
                    done2 = true;
                }
            }
        }        
        // If any of the inorder traversals is over, then break out
        if(val1 >= val2)
            break;

        // If pair found, print it
        if((val1 != val2) and (val1 + val2) == sum) {
            cout << val1 << ' ' << val2 << '\n';
            done1 = done2 = false;
        }
        // If sum of curr values is smaller, move to the next node in Normal Inorder Traversal
        else if(val1 + val2 < sum)
            done1 = false;
        // If sum of curr values is greater, move to the next node in Reverse Inorder Traversal
        else
            done2 = false;
    }
}

// Same approach as in pairsum in binary tree, Time: O(n), Space: O(n)
#include <algorithm>
#include <vector>
// Inorder traversal of BST is always sorted
void convertToArray(BinaryTreeNode<int>* root, vector<int> &output) {
    if (root == NULL) {
        return;
    }
    convertToArray(root -> left, output);
    output.push_back(root -> data);
    convertToArray(root -> right, output);
}
void printNodesSumToS(BinaryTreeNode<int> *root, int sum) {
    vector<int> output;
    convertToArray(root, output);
    // sort(output.begin(), output.end());
    int i = 0, j = output.size() - 1;
    while (i < j) {
        if (output[i] + output[j] == sum) {
            cout << output[i] << " " << output[j] << "\n";
            ++i;
            --j;
        }
        else if (output[i] + output[j] > sum) {
            --j;
        }
        else {
            ++i;
        }
    }
}