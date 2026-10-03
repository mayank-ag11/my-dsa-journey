/***
 * Given a generic tree, find and return the node with second largest value in given tree. Return NULL if no node with required value is present.
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
};
***************/
template <typename T>
class LargestPair {
    public:
    TreeNode<T> *first;
    TreeNode<T> *second;
};

LargestPair<int>* largestPair(TreeNode<int> *root) {
    LargestPair<int>* lp = new LargestPair<int>();
    lp->first = root;
    lp->second = NULL;
    
    for(int i = 0; i < root->numChildren(); i++) {
        LargestPair<int> *childlp = largestPair(root->getChild(i));
        if(childlp->first->data > lp->first->data) {
            if(childlp->second != NULL and childlp->second->data > lp->first->data)
                lp->second = childlp->second;
            else
            	lp->second = lp->first;
            lp->first = childlp->first;
        }
        else if(childlp->first->data < lp->first->data){
            if(lp->second == NULL or lp->second->data < childlp->first->data)
                lp->second = childlp->first;
        }
        else {
            if(lp->second == NULL or 
               childlp->second != NULL and lp->second->data < childlp->second->data)
                lp->second = childlp->second;
        }
    }
    return lp;
}

TreeNode <int>* secondLargest(TreeNode<int> *root) {
    if(root == NULL)
        return NULL;
    
    return largestPair(root)->second;
}

// Coding Ninjas Solution in Java
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
    static class Pair<T> {
        T first;
        T second;
        Pair(T first, T second) {
            this.first = first;
            this.second = second;
        }
    }
    public static TreeNode<Integer> findSecondLargest(TreeNode<Integer> root) {
        return findSecondLargestHelper(root).second;
    }

    public static Pair<TreeNode<Integer>> findSecondLargestHelper(TreeNode<Integer> root) {
        Pair<TreeNode<Integer>> output;
        if (root == null) {
            output = new Pair<TreeNode<Integer>>(null, null);
            return output;
        }
        output = new Pair<TreeNode<Integer>>(root, null);
        for (TreeNode<Integer> child : root.children) {
            Pair<TreeNode<Integer>> childPair = findSecondLargestHelper(child);
            if (childPair.first.data > output.first.data) {
                if (childPair.second == null || childPair.second.data <
                                                    output.first.data)
                {
                    output.second = output.first;
                    output.first = childPair.first;
                }
                else
                {
                    output.first = childPair.first;
                    output.second = childPair.second;
                }
            }
            else if (childPair.first.data.equals(output.first.data) &&
                     childPair.second != null)
            {
                if (output.second == null || childPair.second.data > output.second.data)
                {
                    output.second = childPair.second;
                }
            }
            else if (output.first.data != childPair.first.data && (output.second == null || childPair.first.data > output.second.data))
            {
                output.second = childPair.first;
            }
        }
        return output;
    }
}