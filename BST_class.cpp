#include <iostream>
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
        ~BinaryTreeNode(){
            delete this->left;
            delete this->right;
        }
};
template <typename T>
class BST{
    private:
        BinaryTreeNode<T> *root;//data member
        /************* Functions ******************/
    private:
        bool search_helper(T data,BinaryTreeNode<T> *node){
            /*data dhoondhna in node root walla tree*/
            if(node==NULL){
                return false;
            }
            if(node->data==data){
                return true;
            }
            else if(node->data<=data){
                return search_helper(data,node->right);
            }
            else if(node->data>data){
                return search_helper(data,node->left);
            }
        }
        BinaryTreeNode<T>* insert_helper(T data,BinaryTreeNode<T> *node){
            if(node==NULL){
                BinaryTreeNode<T> *newNode=new BinaryTreeNode<T>(data);
                return newNode;
            }
            if(node->data>data){
                /*matlab left mei insert karna hai*/
                node->left=insert_helper(data,node->left);
            }
            else if(node->data<=data){
                node->right=insert_helper(data,node->right);
            }
            return node; //as above cases mei node did not change
        }
        BinaryTreeNode<T>* remove_helper(T data,BinaryTreeNode<T> *node){
            if(node==NULL){
                return NULL;
            }
            else if(node->data>data){
                /*matlab left subtree se delete*/
                node->left=remove_helper(data,node->left);
                return node;
            }
            else if(node->data<data){
                node->right=remove_helper(data,node->right);
                return node;
            }
            else if(node->data==data){
                if(node->left==NULL and node->right==NULL){
                    delete node;
                    return NULL;
                }
                else if(node->right==NULL and node->left!=NULL){
                    BinaryTreeNode<T> *temp=node->left;
                    node->left=NULL; //connect tod diya now can dlt node
                    delete node;
                    return temp;
                }
                else if(node->right!=NULL and node->left==NULL){
                    BinaryTreeNode<T> *temp=node->right;
                    node->right=NULL;
                    delete node;
                    return temp;
                }
                else if(node->right!=NULL and node->left!=NULL){
                    /*first find left subtree max*/
                    BinaryTreeNode<T> *leftMax=node->left;
                    while(leftMax->right!=NULL){
                        leftMax=leftMax->right;
                    }
                    T MaxLeft=leftMax->data;
                    node->data=MaxLeft;
                    node->left=remove_helper(MaxLeft,node->left);
                    return node;
                }
            }
        }
        void printTree(BinaryTreeNode<T> *root){
            //base case need here
            if(root==NULL){
                return; 
            }
            cout<<root->data<<":";
            if(root->left!=NULL){
                /*then need to print root ka child aur tell recursion
                to print the subtree*/
                /*abhi recursion not call as pehle left subtree
                print se pehle right child of root ie. apna kaam pehle
                khatam karna padhta*/
                cout<<"L:"<<root->left->data<<",";
            }
            if(root->right!=NULL){
                cout<<"R:"<<root->right->data;
            }
            cout<<endl;
            /*ab apna kaam khatam root ke respect mei sab done
            ab recursion call woh subtree print karega*/
            printTree(root->left);//pehle left subtree print
            printTree(root->right);
        }
    public:
        /*constructor*/
        BST(){
            this->root=NULL;
        }
        ~BST(){
            delete this->root;
        }
        bool search(int data){
            /*returns true if element present in tree*/
            return search_helper(data,this->root);
        }
        void insert(int data){ 
            this->root=insert_helper(data,this->root);
        }
        void remove(int data){
            this->root=remove_helper(data,this->root);
        }
        void print(){ 
            printTree(this->root);
        }
};