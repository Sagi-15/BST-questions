#include <iostream>
#include <climits>
#include <vector>
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
vector<int>* getPath(BinaryTreeNode<int> *root , int data){
    if(root==NULL){
        return NULL;
    }
    if(root->data==data){
        vector<int> *output=new vector<int>();
        output->push_back(root->data);
        return output;
    }
    else if(root->data>data){
        vector<int> *leftOutput=getPath(root->left,data);
        if(leftOutput!=NULL){
            leftOutput->push_back(root->data);
            return leftOutput;
        }
        else if(leftOutput==NULL){
            return NULL;
        }
    }
    else if(root->data<data){
        vector<int> *rightOutput=getPath(root->right,data);
        if(rightOutput!=NULL){
            rightOutput->push_back(root->data);
            return rightOutput;
        }
        else if(rightOutput==NULL){
            return NULL;
        }
    }
}