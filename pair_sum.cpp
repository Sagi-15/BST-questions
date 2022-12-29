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
vector<int> v; //ismei push naye elements
vector<int> pairSum_helper(BinaryTreeNode<int> *root){
    if(root==NULL){
        return v;
    }
    v.push_back(root->data);
    pairSum_helper(root->left);
    pairSum_helper(root->right); //aise assume recursion 
    //daal dega vector mei
    return v;
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
    vector<int> tree_vector=pairSum_helper(root);
    for(int i=0;i<tree_vector.size();i++){
        for(int j=i+1;j<tree_vector.size();j++){
            if(tree_vector[i]+tree_vector[j]==sum){
                cout<<min(tree_vector[i],tree_vector[j])<<" "<<max(tree_vector[i],tree_vector[j])<<endl;
            }
        }
    }
}