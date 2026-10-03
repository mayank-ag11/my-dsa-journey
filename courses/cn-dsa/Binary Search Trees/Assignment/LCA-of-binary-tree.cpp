/***
 * Given a binary tree and data of two nodes, find 'LCA' (Lowest Common Ancestor) of the given two nodes in the binary tree.
 * LCA of two nodes A and B is the lowest or deepest node which has both A and B as its descendants.
 * Eg: https://files.codingninjas.in/image1-5333.jpg
 * 
 * Note: It is defined that each node is a descendant to itself, so, if there are two nodes X and Y and X has a direct connection from Y, then Y is the lowest common ancestor.
 * Eg: https://files.codingninjas.in/image2-5334.jpg
 * 
 * Note: 1. If out of 2 nodes only one node is present, return that node. 
         2. If both are not present, return -1.
 ***/
// Better Way (From Solution)
BinaryTreeNode<int> *getLCAHelper(BinaryTreeNode <int>* root , int a, int b) {
    if(root == NULL)
        return NULL;
    
    if(root->data == a or root->data == b)
    	return root;
    
    BinaryTreeNode<int> *left = getLCAHelper(root->left, a, b);
    BinaryTreeNode<int> *right = getLCAHelper(root->right, a, b);
    
    if(left and right)
        return root;
    if(left)
        return left;
    
    return right;
}
int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    BinaryTreeNode<int> *node = getLCAHelper(root, a, b);
    if(node == NULL)
        return -1;
    else
        return node->data;
}

// My first try
class Triplet {
public:
    bool isX;
    bool isY;
    int LCA;
    
    Triplet() {
        isX = false;
        isY = false;
        LCA = -1;
    }
};

Triplet* getLCATriplet(BinaryTreeNode <int>* root , int a, int b) {
    if(root == NULL)
        return NULL;
    
    Triplet *lt = getLCATriplet(root->left, a, b);
    Triplet *rt = getLCATriplet(root->right, a, b);
    Triplet *t = NULL;
    
    if(lt == NULL and rt == NULL) {
        if(root->data == a) {
            t = new Triplet();
            t->isX = true;
            t->LCA = a;
        }
        else if(root->data == b) {
            t = new Triplet();
            t->isY = true;
            t->LCA = b;
        }
    }
    else if(lt != NULL and rt != NULL) {
        t = new Triplet();
        t->isX = true;
        t->isY = true;
        t->LCA = root->data;
    }
    else if(lt != NULL) {
        if(lt->isX and lt->isY)
            t = lt;
        else if(lt->isX) {
            if(root->data == b) {
                t = new Triplet();
                t->isX = true;
        		t->isY = true;
        		t->LCA = root->data;
            }
            else
                t = lt;
        }
        else if(lt->isY) {
            if(root->data == a) {
                t = new Triplet();
                t->isX = true;
        		t->isY = true;
        		t->LCA = root->data;
            }
            else
                t = lt;
        }
    }
    else if(rt != NULL) {
        if(rt->isX and rt->isY)
            t = rt;
        else if(rt->isX) {
            if(root->data == b) {
                t = new Triplet();
                t->isX = true;
        		t->isY = true;
        		t->LCA = root->data;
            }
            else
                t = rt;
        }
        else if(rt->isY) {
            if(root->data == a) {
                t = new Triplet();
                t->isX = true;
        		t->isY = true;
        		t->LCA = root->data;
            }
            else
                t = rt;
        }
    }
    return t;
}

int getLCA(BinaryTreeNode <int>* root , int a, int b) {
    Triplet *t =  getLCATriplet(root, a, b);
    if(t == NULL)
        return -1;
    else
        return t->LCA;
}