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
template <typename T>
class Node{
    public:
        T data;
        Node<T> *next;
        Node(T data){
            this->data=data;
            this->next=NULL;
        }
};
class Pair{
    public:
        Node<int> *head;
        Node<int> *tail;
        Pair(){
            this->head=NULL;
            this->tail=NULL;
        }
};
Pair constructLinkedList_helper(BinaryTreeNode<int>* root){
    if(root==NULL){
        Pair answer;
        return answer;
    }
    /*our small work*/
    Node<int> *root_node=new Node<int>(root->data);
    if(root->left==NULL and root->right==NULL){
        Pair answer;
        answer.head=root_node;
        answer.tail=root_node;
        return answer;
    }
    else if(root->left!=NULL and root->right==NULL){
        Pair answer;
        Pair left_answer=constructLinkedList_helper(root->left);
        answer.head=left_answer.head;
        answer.tail=root_node;
        answer.tail->next=NULL;
        left_answer.tail->next=root_node;
    }
    else if(root->left==NULL and root->right!=NULL){
        Pair answer;
        Pair right_answer=constructLinkedList_helper(root->right);
        answer.head=root_node;
        root_node->next=right_answer.head;
        answer.tail=right_answer.tail;
        answer.tail->next=NULL;
        return answer;
    }
    else if(root->left!=NULL and root->right!=NULL){
        Pair answer;
        Pair left_answer=constructLinkedList_helper(root->left);
        Pair right_answer=constructLinkedList_helper(root->right);
        left_answer.tail->next=root_node;
        answer.head=left_answer.head;
        answer.tail=right_answer.tail;
        root_node->next=right_answer.head;
        answer.tail->next=NULL;
        return answer;
    }
}
Node<int>* constructLinkedList(BinaryTreeNode<int>* root){
    return constructLinkedList_helper(root).head;
}