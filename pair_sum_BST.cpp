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
BinaryTreeNode<int>* next_min(BinaryTreeNode<int> *root){
    while(root->left!=NULL){
        root=root->left;
    }
    return root;
}
BinaryTreeNode<int>* next_max(BinaryTreeNode<int> *root){
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}
#include <stack>
void printNodesSumToS(BinaryTreeNode<int> *root, int sum){
    stack<BinaryTreeNode<int>*> inorder,reverse_inorder;
    BinaryTreeNode<int> *temp=root;
    while(temp->left!=NULL){
        inorder.push(temp);
        temp=temp->left;
    }
    temp=root;
    while(temp->right!=NULL){
        reverse_inorder.push(temp);
        temp=temp->right;
    }
    while((inorder.empty()==true and reverse_inorder.empty()==true)==false){
        if(inorder.top()->data+reverse_inorder.top()->data==sum){
            cout<<inorder.top()<<" "<<reverse_inorder.top()<<endl;
            BinaryTreeNode<int> *in_top=inorder.top();
            BinaryTreeNode<int> *rev_in_top=reverse_inorder.top();
            inorder.pop();
            reverse_inorder.pop();
            if(in_top->left!=NULL){
                inorder.push(next_max(in_top->left));
            }
            if(rev_in_top->right!=NULL){
                reverse_inorder.push(next_min(rev_in_top->right));
            }
        }
        else if(inorder.top()->data+reverse_inorder.top()->data<sum){
            BinaryTreeNode<int> *in_top=inorder.top();
            inorder.pop();
            if(in_top->left!=NULL){
                inorder.push(next_max(in_top->left));
            }
        }
        else if(inorder.top()->data+reverse_inorder.top()->data>sum){
            BinaryTreeNode<int> *rev_in_top=reverse_inorder.top();
            reverse_inorder.pop();
            if(rev_in_top->right!=NULL){
                inorder.push(next_max(rev_in_top->right));
            }
        }
    }
}