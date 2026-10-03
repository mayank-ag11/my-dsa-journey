/***
 * Given a generic tree and an integer x, check if x is present in the given tree or not. Return true if x is present, return false otherwise.
 ***/
// Following is the Tree node structure
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
};
***************/

bool containsX(TreeNode<int>* root, int x) {
    if(root == NULL)
        return false;
    if(root->data == x)
        return true;
    
    for(int i = 0; i < root->numChildren(); i++) {
        bool ans = containsX(root->getChild(i), x);
        if(ans)
            return true;
    }
    return false;
}

/*
    Time complexity: O(N)
    Space complexity: O(H)
    where N is the number of nodes in the tree and
    H is the height/depth of the tree
*/
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
    public static boolean checkIfContainsX(TreeNode<Integer> root, int x) {
        if (root == null)
            return false;

        if (root.data == x)
            return true;

        for (TreeNode<Integer> child : root.children) {
            if (checkIfContainsX(child, x))
                return true;
        }
        return false;
    }
}