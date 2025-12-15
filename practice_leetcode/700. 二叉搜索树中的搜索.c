#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
struct TreeNode* searchBST(struct TreeNode* root, int val) {
    if(root==NULL)return NULL;
    if(root->val==val)return root;
    
    if(root->val<val){
      return  searchBST(root->right,val);
    }
    if(root->val>val){
        return searchBST(root->left,val);}
        return NULL;
}