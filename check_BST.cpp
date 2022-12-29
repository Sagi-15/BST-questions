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
#include <climits>
bool isBST_helper(BinaryTreeNode<int> *root,int min,int max){
    /*min and max is the minimum and maximum value root
    node can have*/
    if(root==NULL){
        return true;
    }
    if(root->data>=min and root->data<max){
        /*yeh condition tabhi aage badh*/
        /*left subtree check same question bass min aur max
        for root node badal gaya*/
        bool left_answer=isBST_helper(root->left,min,root->data);
        bool right_answer=isBST_helper(root->right,root->data,max);
        if(left_answer==true and right_answer==true){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}
bool isBST(BinaryTreeNode<int> *root){
	return isBST_helper(root,INT_MIN,INT_MAX);
}