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

void postorder(TreeNode*root){
    if(root==NULL) return ;
     postorder(root->left);
    
    postorder(root->right);
    printf("%d->",root->val);


}