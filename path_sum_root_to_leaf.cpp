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
class Pair{
    public:
        vector<int> path;
        int sum;
        Pair(){
            this->sum=0;
        }
};
vector<Pair> rootToLeafPathsSumToK_helper(BinaryTreeNode<int> *root){
    if(root==NULL){
        vector<Pair> answer;
        return answer;
    }
    vector<Pair> left=rootToLeafPathsSumToK_helper(root->left);
    vector<Pair> right=rootToLeafPathsSumToK_helper(root->right);
    vector<Pair> answer;
    for(int i=0;i<left.size();i++){
        left[i].path.push_back(root->data);
        left[i].sum+=root->data;
        answer.push_back(left[i]);
    }
    for(int i=0;i<right.size();i++){
        right[i].path.push_back(root->data);
        right[i].sum+=root->data;
        answer.push_back(right[i]);
    }
    return answer;
}
void rootToLeafPathsSumToK(BinaryTreeNode<int> *root, int k){
    vector<Pair> answer=rootToLeafPathsSumToK_helper(root);
    for(int i=0;i<answer.size();i++){
        if(answer[i].sum==k){
            for(int j=answer[i].path.size()-1;j>=0;j--){
                cout<<answer[i].path[j]<<" ";
            }
            cout<<endl;
        }
    }
}  