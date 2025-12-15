#include<stdio.h>
#include<stdlib.h>
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
void preOrder(TreeNode* root) {
    
    if (root == NULL) {
        return;
    }

    printf("%d -> ", root->val);

  
    preOrder(root->left);  
    
   
    preOrder(root->right);
}

TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int main() {
    
    TreeNode* root = createNode(1);      
    root->left = createNode(2);          
    root->right = createNode(3);         

   
    printf("开始前序遍历: ");
    preOrder(root); 
    printf("结束\n");

    // 预期输出: 1 -> 2 -> 3 -> 结束
    return 0;
}