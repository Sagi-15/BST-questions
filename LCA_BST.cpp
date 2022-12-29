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
    if(val1<root->data and val2<root->data){
        return getLCA(root->left,val1,val2);
    }
    else if(val1>root->data and val2>root->data){
        return getLCA(root->right,val1,val2);
    }
    else{
        return root->data;
    }
}