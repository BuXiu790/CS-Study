#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
struct TreeNode* lowestCommonAncestor(struct TreeNode* root, struct TreeNode* p, struct TreeNode* q) {
    if(root==NULL)return NULL;
    if(root==p||root==q)return root;
    if(p->val>root->val&&q->val>root->val){
struct TreeNode*right=lowestCommonAncestor(root->right,p,q);
return right;
    }
    if(p->val<root->val&&q->val<root->val){
         struct TreeNode*left=lowestCommonAncestor(root->left,p,q);
         return left;
    }
return root;
   
}