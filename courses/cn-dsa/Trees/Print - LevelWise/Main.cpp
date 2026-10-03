#include <iostream>
using namespace std;
#include "TreeNode.h"
#include "Queue.h"
#include "PrintLevelWise.cpp"

TreeNode<int>* takeInputLevelWise() {
    Queue<TreeNode<int>*> q;
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);
    q.enqueue(root);
    while (!q.isEmpty()) {
        TreeNode<int>* frontNode = q.dequeue();
        int numChildren;
        cin >> numChildren;
        for (int i = 0; i < numChildren; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* childNode = new TreeNode<int>(childData);
            q.enqueue(childNode);
            frontNode->addChild(childNode);
        }
    }
    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    printLevelWise(root);
}