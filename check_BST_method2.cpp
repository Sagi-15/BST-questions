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
class Triplet{
    public:
        int min;
        int max;
        bool isBST;
        Triplet(int min=INT_MAX,int max=INT_MIN,bool isBST=true){
            /*helper base case sochke default parameters*/
            this->min=min;
            this->max=max;
            this->isBST=isBST;
        }
};
Triplet isBST_helper(BinaryTreeNode<int> *root){
    if(root==NULL){
        Triplet answer;
        return answer;
    }
    Triplet left_ke_saare_answers=isBST_helper(root->left);
    Triplet right_ke_saare_answers=isBST_helper(root->right);
    int left_max=left_ke_saare_answers.max;
    int right_min=right_ke_saare_answers.min;
    bool is_left_subtree_BST=left_ke_saare_answers.isBST;
    bool is_right_subtree_BST=right_ke_saare_answers.isBST;
    if(root->data>left_max and root->data<=right_min and is_left_subtree_BST==true and is_right_subtree_BST==true){
        /*matlab BST hai so left ka min will be min and right ka 
        max wd be max*/
        Triplet answer(left_ke_saare_answers.min,right_ke_saare_answers.max,true);
        return answer;
    }
    else{
        /*can't say about overall max so need to compare*/
        int overall_max=max(left_ke_saare_answers.max,max(root->data,right_ke_saare_answers.max));
        int overall_min=min(left_ke_saare_answers.min,min(root->data,right_ke_saare_answers.min));
        Triplet answer(overall_min,overall_max,false);
        return answer;
    }
}
bool isBST(BinaryTreeNode<int> *root){
    return isBST_helper(root).isBST;
}