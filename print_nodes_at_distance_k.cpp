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
void print_at_depth_k(BinaryTreeNode<int> *node,int k){
    if(k<0){
        return;
    }
    if(k==0){
        cout<<node->data<<endl;
    }
    else if(k>0){
        print_at_depth_k(node->left,k-1);
        print_at_depth_k(node->right,k-1);
    }
}
int nodesAtDistanceK_helper(BinaryTreeNode<int> *root, int node, int k){
    if(root==NULL){
        return -1;
    }
    if(root->data==node){
        print_at_depth_k(root,k);
        return 0;
    }
    else{
        int left_distance=nodesAtDistanceK_helper(root->left,node,k);
        if(left_distance!=-1){
            /*our work do*/
            if(left_distance+1==k){
                cout<<root->data<<endl;
            }
            else{
                print_at_depth_k(root->right,k-left_distance-3);
            }
        }
        int right_distance=nodesAtDistanceK_helper(root->right,node,k);
        if(right_distance!=-1){
            if(right_distance+1==k){
                cout<<root->data<<endl;
            }
            else{
                print_at_depth_k(root->left,k-right_distance-3);
            }
        }
        if(left_distance!=-1){
            return left_distance+1;
        }
        else if(right_distance!=-1){
            return right_distance+1;
        }
        else if(left_distance==-1 and right_distance==-1){
            return -1;
        }
    }
}
void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k){
    nodesAtDistanceK_helper(root,node,k);
}