#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
bool helper(struct TreeNode*root,long long lower,long long upper){
   if(root==NULL) return true;
   if(root->val<=lower||root->val>=upper){
    return false;
   }
   
   return helper(root->left,lower,root->val)&&helper(root->right,root->val,upper);
 

}
bool isValidBST(struct TreeNode* root) {
    return helper(root,-2147483649LL,2147483648LL);

}