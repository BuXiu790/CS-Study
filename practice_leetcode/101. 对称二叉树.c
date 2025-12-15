#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

bool helper(TreeNode*left,TreeNode*right){
    if(left==NULL&&right==NULL)return true;
    if(left==NULL||right==NULL)return false;
    if(left->val!=right->val)return false;
    if (left->val != right->val) {
        return false;
    }
    //判断左边的左边等于右边的右边
   return (helper(left->left,right->right)&&helper(left->right,right->left));   
}
bool isSymmetric(struct TreeNode* root) {
    if(root==NULL)return true;
    return helper(root->left, root->right);
}