#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;
typedef struct Node{
    struct TreeNode* treeNode;
    struct Node*next;
}Node;

//定义队列
typedef struct {
    Node*front;
    Node*rear;
}Queue;


//创建一个空队
Queue *createQueue(){
    Queue *q=(Queue*)malloc(sizeof(Queue));
    q->front=NULL;
    q->rear=NULL;
    return q;
}

//入队
void enqueue(Queue*q,TreeNode*node){
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->treeNode=node;
    newNode->next=NULL;
    if(q->rear == NULL){
       q->front=newNode;
       q->rear=newNode;
    }else{
        q->rear->next=newNode;
        q->rear=newNode;
    }
}

//出队
struct TreeNode* dequeue(Queue*q){
    if(q->front==NULL){
        
        return NULL;
    }
    Node*temp=q->front;
   struct TreeNode* ret = temp->treeNode;
    q->front=q->front->next;
    //判断当队空是，rear指向空
    if(q->front==NULL){
        q->rear=NULL;}
    free(temp);
    return ret;
}

TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
void levelOrder(TreeNode* root){
    if(root==NULL) return;

    Queue*queue=createQueue();
    enqueue(queue,root);
    while(queue->front!=NULL){
        TreeNode*current=dequeue(queue);
        printf("%d ",current->val);
        if(current->left!=NULL){
            enqueue(queue,current->left);
        }
        if(current->right!=NULL){
            enqueue(queue,current->right);
        }

    }
}

