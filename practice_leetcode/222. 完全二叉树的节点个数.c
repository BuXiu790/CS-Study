#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
int countNodes(struct TreeNode* root) {
   if(root==NULL)return 0;
   return countNodes(root->left)+countNodes(root->right)+1;
}