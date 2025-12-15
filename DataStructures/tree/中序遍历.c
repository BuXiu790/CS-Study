#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode{
int val;
struct TreeNode*left;
struct TreeNode*right;

}TreeNode;

TreeNode*createNode(TreeNode*root,int val){
TreeNode*Newnode=(TreeNode*)malloc(sizeof(TreeNode));
Newnode->left=NULL;
Newnode->right=NULL;
Newnode->val=val;
return Newnode;
}

void inorder(TreeNode*root){
    if(root==NULL) return ;
     inorder(root->left);
    printf("%d->",root->val);
    inorder(root->right);


}