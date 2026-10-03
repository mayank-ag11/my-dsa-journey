/***
 * Remove all leaf nodes from a given generic Tree. Leaf nodes are those nodes, which don't have any children.
 * Note : Root will also be a leaf node if it doesn't have any child. You don't need to print the tree, just remove all leaf nodes and return the updated root.
 ***/

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
    void removeChild(int index);
 
};
***************/
TreeNode<int>* removeLeafNodes(TreeNode<int>* root) {
    if(root == NULL)
        return NULL;
    if(root->numChildren() == 0) {
        delete root;
        return NULL;
    }
    
    for(int i = 0; i < root->numChildren(); i++) {
        TreeNode<int> *child = root->getChild(i);
        child = removeLeafNodes(child);
        if(child == NULL) {
            root->removeChild(i);
            i--;
        }
    }
    
    return root;
}

// Java Solution
import java.util.ArrayList;
public class Solution {
    /* TreeNode structure
    *
    * class TreeNode<T> {
    T data;
    ArrayList<TreeNode<T>> children;
    TreeNode(T data){
    this.data = data;
    children = new ArrayList<TreeNode<T>>();
    }
    }*/
    public static TreeNode < Integer > removeLeafNodes(TreeNode < Integer > root) {
        if (root == null || root.children.size() == 0) {
            return null;
        }
        ArrayList < Integer > indexes = new ArrayList < Integer > ();
        for (int i = 0; i < root.children.size(); i++) {
            TreeNode < Integer > child = root.children.get(i);
            if (child.children.size() == 0) {
                indexes.add(i);
            }
        }
        for (int i = indexes.size() - 1; i >= 0; i--) {
            int j = indexes.get(i);
            root.children.remove(j);
        }
        for (int i = 0; i < root.children.size(); i++) {
            TreeNode < Integer > child = removeLeafNodes(root.children.get(i));
            if (child == null) {
                root.children.remove(i);
            }
        }
        return root;
    }
}