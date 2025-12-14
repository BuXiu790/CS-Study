#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
typedef int E;
//定义数据类型
typedef struct Node{
    E val;
    struct Node*next;
}Node;

typedef struct Stack{
    struct Node*top;
}Stack;

Stack *createStack(){
    Stack*stack=(Stack*)malloc(sizeof(Stack));
    stack->top=NULL;
    return stack;
}

void push(Stack*stack,E val){
    Node*node=(Node*)malloc(sizeof(Node));
    node->next=stack->top;
    stack->top=node;
    node->val=val;
}

E pop(Stack*stack){
    if(stack->top==NULL){
    printf("stack is empty");
    return -9999;
}
    Node*temp=stack->top;
    E val=temp->val;
    stack->top=stack->top->next;
    free(temp);
    return val;
}

typedef struct {
    Stack *stackin;
    Stack *stackout;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue*queue=(MyQueue*)malloc(sizeof(MyQueue));
    Stack *stackin=(Stack*)malloc(sizeof(Stack));
    Stack *stackout=(Stack*)malloc(sizeof(Stack));
    stackin->top=NULL;
    stackout->top=NULL;
    queue->stackin=stackin;
    queue->stackout=stackout;
    return queue;
}

void myQueuePush(MyQueue* obj, int x) {
    push(obj->stackin,x);
}

int myQueuePop(MyQueue* obj) {
    //判断stackout是否为空，若为空再把stackin的转入stackout
    if(obj->stackout->top==NULL){
        while(obj->stackin->top!=NULL){
        push(obj->stackout,pop(obj->stackin));}
    }
    return pop(obj->stackout);
}

int myQueuePeek(MyQueue* obj) {
    if(obj->stackout->top==NULL){
        while(obj->stackin->top!=NULL){
        push(obj->stackout,pop(obj->stackin));}
    }
    return obj->stackout->top->val;
}

bool myQueueEmpty(MyQueue* obj) {
    if(obj->stackout->top==NULL&&obj->stackin->top==NULL){
        return true;
    }
    else return false; 
}

void clearStack(Stack* stack) {
    while (stack->top != NULL) {
        Node* temp = stack->top;
        stack->top = stack->top->next;
        free(temp);}}
        
void myQueueFree(MyQueue* obj) {
  
    clearStack(obj->stackin);
    clearStack(obj->stackout);
     free(obj->stackin);
     free(obj->stackout);
     free(obj);
}