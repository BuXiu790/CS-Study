#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
//定义节点
typedef struct Node{
    int val;
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
void enqueue(Queue*q,int val){
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->val=val;
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
int dequeue(Queue*q){
    if(q->front==NULL){
        printf("error");
        return -1;
    }
    Node*temp=q->front;
    int val=temp->val;
    q->front=q->front->next;
    //判断当队空是，rear指向空
    if(q->front==NULL){
        q->rear=NULL;}
    free(temp);
    return val;
}

//test
int main() {
    Queue* q = createQueue();
    
    
    printf("Enqueue: 10, 20, 30\n");
    enqueue(q, 10);
    enqueue(q, 20);
    enqueue(q, 30);
    
    printf("Dequeue: %d\n", dequeue(q)); // 期待 10
    printf("Dequeue: %d\n", dequeue(q)); // 期待 20
    
   
    printf("Enqueue: 40\n");
    enqueue(q, 40);
    
    
    printf("Dequeue: %d\n", dequeue(q)); // 期待 30
    printf("Dequeue: %d\n", dequeue(q)); // 期待 40
    
    return 0;
}