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
bool search_in_subtree(BinaryTreeNode<int> *node,int data){
    if(node==NULL){
        return false;
    }
    if(node->data==data){
        return true;
    }
    else{
        return (search_in_subtree(node->left,data)==true or search_in_subtree(node->right,data)==true);
    }
}
int getLCA(BinaryTreeNode<int>* root , int val1 , int val2){
    if(root==NULL){
        return -1;
    }
    else if(search_in_subtree(root,val1)==false or search_in_subtree(root,val2)==false){
        /*ie. koi ek present hi nahi*/
        return -1;
    }
    if(search_in_subtree(root->left,val1) and search_in_subtree(root->left,val1)){
        return getLCA(root->left,val1,val2);
    }
    else if(search_in_subtree(root->right,val1) and search_in_subtree(root->right,val2)){
        return getLCA(root->right,val1,val2);
    }
    else{
        return root->data;
    }
}