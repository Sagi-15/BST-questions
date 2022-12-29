#include <iostream>
#include <climits>
using namespace std;
template <typename T>
class BinaryTreeNode{
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        BinaryTreeNode(T data=0){
            this->data=data;
            this->left=NULL;
            this->right=NULL;
        }
};
BinaryTreeNode<int>* insertDuplicateNode_helper(BinaryTreeNode<int> *root){
    /*base case*/
    if(root==NULL){
        return NULL;
    }
    /*our small work*/
    BinaryTreeNode<int> *root_duplicate=new BinaryTreeNode<int>(root->data);
    BinaryTreeNode<int> *root_previous_left_subtree=root->left;
    root->left=root_duplicate;
    /*now assume root ke prev left subtree
    mei aise left mei insert karke
    subtree naya walla recursion laa dega as same problem on smaller 
    tree so jod denge*/
    root_duplicate->left=insertDuplicateNode_helper(root_previous_left_subtree);
    root->right=insertDuplicateNode_helper(root->right);
    return root;
}
void insertDuplicateNode(BinaryTreeNode<int> *root){
    root=insertDuplicateNode_helper(root);
}