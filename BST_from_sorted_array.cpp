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
BinaryTreeNode<int>* constructTree_helper(int *input,int start_index,int end_index){
    /*base case empty array*/
    if(start_index>end_index){
        return NULL;
    }
    int mid=(start_index+end_index)/2;
    BinaryTreeNode<int> *root=new BinaryTreeNode<int>(input[mid]);
    BinaryTreeNode<int> *left_subtree_root=constructTree_helper(input,start_index,mid-1);
    BinaryTreeNode<int> *right_subtree_root=constructTree_helper(input,mid+1,end_index);
    root->left=left_subtree_root;
    root->right=right_subtree_root;
    return root;
}
BinaryTreeNode<int>* constructTree(int *input, int n){
	return constructTree_helper(input,0,n-1);
}