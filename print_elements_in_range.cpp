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
void elementsInRangeK1K2(BinaryTreeNode<int>* root, int k1, int k2){
	if(root==NULL){
        return;
    }
    if(root->data>=k1 and root->data<=k2){
        elementsInRangeK1K2(root->left,k1,k2);
        cout<<root->data<<" ";
        elementsInRangeK1K2(root->right,k1,k2);
    }
    else if(root->data>k2){
        elementsInRangeK1K2(root->left,k1,k2);
    }
    else if(root->data<k1){
        elementsInRangeK1K2(root->right,k1,k2);
    }
}