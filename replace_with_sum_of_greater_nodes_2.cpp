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
#include <vector>
vector<BinaryTreeNode<int>*> answer;
vector<BinaryTreeNode<int>*> replaceWithLargerNodesSum_helper(BinaryTreeNode<int> *root){
    if(root==NULL){
        return answer;
    }
    replaceWithLargerNodesSum_helper(root->left);
    answer.push_back(root);
    replaceWithLargerNodesSum_helper(root->right);
    return answer;
}    
void replaceWithLargerNodesSum(BinaryTreeNode<int> *root){
    vector<BinaryTreeNode<int>*> inorder_array=replaceWithLargerNodesSum_helper(root);
    int j=inorder_array.size()-1;
    while(j>0){
        inorder_array[j-1]->data=inorder_array[j-1]->data+inorder_array[j]->data;
        j--;
    }
}