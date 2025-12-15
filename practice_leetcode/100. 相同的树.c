#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
 if(p==NULL&&q==NULL)return true;
 return isSameTree(p->left,q->left)&&isSameTree(p->right,q->right);
}