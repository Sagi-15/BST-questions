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
int getLCA(BinaryTreeNode<int>* root , int val1 , int val2){
    if(root==NULL){
        return -1;
    }
    if(val1==root->data or val2==root->data){
        return root->data;
    }
    else{
        int left_subtree_LCA=getLCA(root->left,val2,val2);
        int right_subtree_LCA=getLCA(root->right,val1,val2);
        if(left_subtree_LCA==-1 and right_subtree_LCA!=-1){
            return right_subtree_LCA;
        }
        else if(right_subtree_LCA==-1 and left_subtree_LCA!=-1){
            return left_subtree_LCA;
        }
        else if(right_subtree_LCA!=-1 and left_subtree_LCA!=-1){
            return root->data;
        }
        else if(right_subtree_LCA==-1 and left_subtree_LCA==-1){
            return -1;
        }
    }
}