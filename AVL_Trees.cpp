#include <iostream>
using namespace std;
template <typename T>
class AVL_TreeNode{
    public:
        T data;
        AVL_TreeNode<T> *left;
        AVL_TreeNode<T> *right;
        int height_of_node;
        /*constructor*/
        AVL_TreeNode(T data=0){
            /*height is set to 0 for new Node
            as in BST always node is inserted
            at the edge so height 0 hi hogi
            aur jaise jaise uske baad node insert
            height update karte jaayenge*/
            this->data=data;
            this->left=NULL;
            this->right=NULL;
            this->height_of_node=1;
        }
        ~AVL_TreeNode(){
            delete this->left;
            delete this->right;
        }
};
template <typename T>
class AVL_Tree{
    private:
        /*only one data member root of AVL tree*/
        AVL_TreeNode<T> *root;
        /*Balance Factor*/
        int BalanceFactor(AVL_TreeNode<T> *node){
            if(node==NULL or (node->left==NULL and node->right==NULL)){
                return 0;
            }
            else if(node->left==NULL and node->right!=NULL){
                return -((node->right)->height_of_node);
            }
            else if(node->left!=NULL and node->right==NULL){
                return (node->left)->height_of_node;
            }
            else if(node->left!=NULL and node->right!=NULL){
                return ((node->left)->height_of_node)-((node->right)->height_of_node);
            }
        }
        /*assigning height to all nodes function for helping Rotation*/
        int assign_height(AVL_TreeNode<T> *node){
            if(node==NULL){
                return 0;
            }
            /*saath mei height bhi assign aur return bhi kar*/
            int left_subtree_of_node_ka_height=assign_height(node->left);
            int right_subtree_of_node_ka_height=assign_height(node->right);
            node->height_of_node=1+max(left_subtree_of_node_ka_height,right_subtree_of_node_ka_height);
            return node->height_of_node;
        }
        /*defining all the rotations*/
        AVL_TreeNode<T>* LL_Rotation(AVL_TreeNode<T> *node){
            AVL_TreeNode<T> *temp=(node->left)->right;
            (node->left)->right=node;
            node->left=temp;
            if(this->root==node){
                this->root=node->left;
            }
            assign_height(node->left);
            return node->left;
        }
        AVL_TreeNode<T>* LR_Rotation(AVL_TreeNode<T> *node){
            /*made same notations as in copy*/
            AVL_TreeNode<T> *A=node,*B=node->left,*C=(node->left)->right;
            AVL_TreeNode<T> *C_left=C->left;
            AVL_TreeNode<T> *C_right=C->right;
            C->right=A;
            C->left=B;
            B->right=C_left;
            A->left=C_right;
            assign_height(C);
            if(this->root==A){
                this->root=C;
            }
            return C;
        }
        AVL_TreeNode<T>* RL_Rotation(AVL_TreeNode<T> *node){
            AVL_TreeNode<T> *A=node,*B=node->right,*C=(node->right)->left;
            AVL_TreeNode<T> *C_left=C->left;
            AVL_TreeNode<T> *C_right=C->right;
            C->left=A;
            C->right=B;
            A->right=C_left;
            B->left=C_right;
            assign_height(C);
            if(this->root==A){
                this->root=C;
            }
            return C;
        }
        AVL_TreeNode<T>* RR_Rotation(AVL_TreeNode<T> *node){
            AVL_TreeNode<T> *A=node,*B=node->right,*C=(node->right)->right;
            AVL_TreeNode<T> *B_left=B->left;
            B->left=A;
            B->right=C;
            A->right=B_left;
            assign_height(B);
            if(this->root==A){
                this->root=B;
            }
            return B;
        }
    public:
        /*constructor*/
        AVL_Tree(){
            this->root=NULL;
        }
        /*destructor*/
        ~AVL_Tree(){
            delete this->root;
        }
        /*Search Function*/
    private:
        bool search_helper(T data,AVL_TreeNode<T> *node){
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
    public:
        bool search(int data){
            /*returns true if element present in tree*/
            return search_helper(data,this->root);
        }
    private:
        AVL_TreeNode<T>* insert_helper(T data,AVL_TreeNode<T> *node){
            if(node==NULL){
                /*aur height=0 default set kar diya*/
                //cout<<"called base case"<<endl;
                AVL_TreeNode<T> *newNode=new AVL_TreeNode<T>(data);
                return newNode;
            }
            if(node->data>data){
                /*matlab left mei insert karna hai*/
                //cout<<"called data less"<<endl;
                node->left=insert_helper(data,node->left);
            }
            else if(node->data<=data){
                //cout<<"called data more"<<endl;
                node->right=insert_helper(data,node->right);
                //cout<<node->data<<" ";
            }
            assign_height(this->root);
            /*cout<<"For node"<<node->data<<endl;
            cout<<node->height_of_node<<endl;
            cout<<BalanceFactor(node)<<" "<<BalanceFactor(node->right)<<endl;*/
            /*now insert karne ke baad node ka balance factor
            +2 or -2 then rotation*/
            AVL_TreeNode<T> *subtree_after_rotation=node;//agar no change ie. balanced so root hi return
            //cout<<"Balance Factor of "<<node->data<<BalanceFactor(node)<<endl;
            if(BalanceFactor(node)==2 and BalanceFactor(node->left)==1){
                /*matlab LL-imbalance*/
                //cout<<"called LL"<<endl;
                subtree_after_rotation=LL_Rotation(node);
                //return subtree_after_rotation;
            }
            else if(BalanceFactor(node)==2 and BalanceFactor(node->left)==-1){
                /*matlab LR-imbalance*/
                //cout<<"called LR"<<endl;
                subtree_after_rotation=LR_Rotation(node);
                //return subtree_after_rotation;
            }
            else if(BalanceFactor(node)==-2 and BalanceFactor(node->right)==1){
                /*matlab RL-imbalance*/
                //cout<<"called RL"<<endl;
                subtree_after_rotation=RL_Rotation(node);
                //return subtree_after_rotation;
            }
            else if(BalanceFactor(node)==-2 and BalanceFactor(node->right)==-1){
                /*matlab RR-imbalance*/
                //cout<<"called RR"<<endl;
                subtree_after_rotation=RR_Rotation(node);
                //return subtree_after_rotation;
            }
            return subtree_after_rotation;
        }
    public:
        void insert(int data){ 
            this->root=insert_helper(data,this->root);
        }
    private:
        AVL_TreeNode<T>* check_imbalance_and_return_balanced_subtree(AVL_TreeNode<T> *node){
            if(BalanceFactor(node)==2 and BalanceFactor(node->left)==1){
                /*case L1*/
                return LL_Rotation(node);
            }
            else if(BalanceFactor(node)==2 and BalanceFactor(node->left)==-1){
                /*case L-1*/
                return LR_Rotation(node);
            }
            if(BalanceFactor(node)==2 and BalanceFactor(node->left)==0){
                /*case L0*/
                return LL_Rotation(node);
            }
            if(BalanceFactor(node)==-2 and BalanceFactor(node->left)==1){
                /*case R1*/
                return RL_Rotation(node);
            }
            if(BalanceFactor(node)==-2 and BalanceFactor(node->left)==-1){
                /*case R-1*/
                return RR_Rotation(node);
            }
            if(BalanceFactor(node)==-2 and BalanceFactor(node->left)==0){
                /*case R0*/
                return RR_Rotation(node);
            }
        }
        AVL_TreeNode<T>* remove_helper(T data,AVL_TreeNode<T> *node){
            if(node==NULL){
                return NULL;
            }
            else if(node->data>data){
                /*matlab left subtree se delete*/
                node->left=remove_helper(data,node->left);
                AVL_TreeNode<T> *node_left_after_rotation=check_imbalance_and_return_balanced_subtree(node->left);
                node->left=node_left_after_rotation;
                assign_height(this->root);
                return node;
            }
            else if(node->data<data){
                node->right=remove_helper(data,node->right);
                AVL_TreeNode<T> *node_right_after_rotation=check_imbalance_and_return_balanced_subtree(node->right);
                node->right=node_right_after_rotation;
                assign_height(this->root);
                return node;
            }
            else if(node->data==data){
                if(node->left==NULL and node->right==NULL){
                    delete node;
                    return NULL;
                }
                else if(node->right==NULL and node->left!=NULL){
                    AVL_TreeNode<T> *temp=node->left;
                    node->left=NULL; //connect tod diya now can dlt node
                    /*as yeh balanced hi tha left subtree root
                    hata diya toh imbalanced ho jaana is impossible*/
                    delete node;
                    return temp;
                }
                else if(node->right!=NULL and node->left==NULL){
                    AVL_TreeNode<T> *temp=node->right;
                    node->right=NULL;
                    delete node;
                    return temp;
                }
                else if(node->right!=NULL and node->left!=NULL){
                    /*first find left subtree max*/
                    AVL_TreeNode<T> *leftMax=node->left;
                    while(leftMax->right!=NULL){
                        leftMax=leftMax->right;
                    }
                    T MaxLeft=leftMax->data;
                    node->data=MaxLeft;
                    node->left=remove_helper(MaxLeft,node->left);
                    /*now may become imbalance*/
                    AVL_TreeNode<T> *node_after_rotation=check_imbalance_and_return_balanced_subtree(node);
                    assign_height(node_after_rotation);
                    return node_after_rotation;
                }
            }
        }
    public:
        void remove(int data){
            this->root=remove_helper(data,this->root);
        }
    private:
        void printTree(AVL_TreeNode<T> *root){
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
        void print(){ 
            printTree(this->root);
        }
};
int main(){
    AVL_Tree<int> avl;
    avl.insert(1);
    avl.insert(2);
    avl.insert(3);
    avl.insert(4);
    avl.insert(5);
    avl.insert(6);
    avl.insert(8);
    avl.insert(9);
    avl.insert(10);
    avl.insert(7);
    avl.insert(11);
    avl.print();
}