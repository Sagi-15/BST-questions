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
#include <algorithm>
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
void pairSum(BinaryTreeNode<int> *root, int sum){
    vector<int> element_array=pairSum_helper(root);
    int A[element_array.size()];
    for(int i=0;i<element_array.size();i++){
        A[i]=element_array[i];
    }
    sort(A,A+element_array.size());
    int i=0,j=element_array.size()-1;
    while(i<=j){
        if(A[i]+A[j]==sum){
            cout<<A[i]<<" "<<A[j]<<endl;
            i++;
            j--;
        }
        else if(A[i]+A[j]<sum){
            /*sum mei kami aa rhi so increase min walli*/
            i++;
        }
        else if(A[i]+A[j]>sum){
            /*sum mei jyada add so bada walla decrease*/
            j--;
        }
    }
}