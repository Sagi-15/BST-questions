#include <iostream>
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
bool searchInBST(BinaryTreeNode<int> *root , int k){
    if(root==NULL){
        return false;
    }
    if(root->data==k){
        return true; //agar root mei hi mil gya toh present hai hi
    }
    else if(root->data>k){
        /*matlab left subtree mei k present ho skta
        joh answer left dega wahi ans*/
        return searchInBST(root->left,k);
    }
    else if(root->data<k){
        /*search in right subtree*/
        return searchInBST(root->right,k);
    }
}