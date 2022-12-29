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
#include <climits>
class Collection{
    public:
        int min_node_value;
        int max_node_value;
        bool isBST;
        int height;
        int height_of_max_BST;
};
Collection largestBSTSubtree_helper(BinaryTreeNode<int> *root){
    if(root==NULL){
        Collection ans;
        ans.isBST=true;
        ans.max_node_value=INT_MIN;
        ans.min_node_value=INT_MAX;
        ans.height=0;
        ans.height_of_max_BST=0;
        return ans;
    }
    Collection left=largestBSTSubtree_helper(root->left);
    Collection right=largestBSTSubtree_helper(root->right);
    int left_subtree_max=left.max_node_value;
    int right_subtree_min=right.min_node_value;
    if(left_subtree_max<root->data and root->data<right_subtree_min and left.isBST==true and right.isBST==true){
        Collection ans;
        ans.min_node_value=min(root->data,min(left.min_node_value,right.min_node_value));
        ans.max_node_value=max(root->data,max(left.max_node_value,right.max_node_value));
        ans.height=1+max(left.height,right.height);
        ans.isBST=true;
        ans.height_of_max_BST=ans.height;
        return ans;
    }
    else{
        Collection ans;
        ans.min_node_value=min(root->data,min(left.min_node_value,right.min_node_value));
        ans.max_node_value=max(root->data,max(left.max_node_value,right.max_node_value));
        ans.isBST=false;
        ans.height=1+max(left.height,right.height);
        ans.height_of_max_BST=max(left.height_of_max_BST,right.height_of_max_BST);
        return ans;
    }
}
int largestBSTSubtree(BinaryTreeNode<int> *root){
    return largestBSTSubtree_helper(root).height_of_max_BST;
}