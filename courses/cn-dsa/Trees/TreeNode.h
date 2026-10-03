template <typename T>
class TreeNode {
    TreeNode<T>** children;
    int childCount;
    int maxChildCount;
public:
    T data;
    
    TreeNode(T data) {
        this->data = data;
        childCount = 0;
        children = new TreeNode<T>*[10];
        maxChildCount = 10;
    }
    
    int numChildren() {
        return childCount;
    }
    
    void addChild(TreeNode<T>* child) {
        children[childCount] = child;
        childCount++;
        if(childCount == maxChildCount) {
            TreeNode<T>** childrenNew = new TreeNode<T>*[2*maxChildCount];
            for(int i = 0; i < maxChildCount; i++) {
                childrenNew[i] = children[i];
            }
            maxChildCount *= 2;
            children = childrenNew;
        }
    }
    
    TreeNode<T>* getChild(int index) {
        return children[index];
    }
    
    void setChild(int index, TreeNode<T>* child) {
        children[index] = child;
    }
};