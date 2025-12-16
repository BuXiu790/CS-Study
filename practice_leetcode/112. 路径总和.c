#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
bool hasPathSum(struct TreeNode* root, int targetSum) {
    if(root==NULL)return false;
    targetSum= targetSum-root->val;
   if (root->left == NULL && root->right == NULL) {
        return targetSum == 0; // 如果余额是0返回true，否则false
    }
   return  hasPathSum(root->left,targetSum)|| hasPathSum(root->right,targetSum);
    
     
}