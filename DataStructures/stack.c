#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
//定义节点
typedef struct Node{
    int val;
   struct Node*next;
}Node;

//定义栈
typedef struct{
    struct Node* top;
}Stack;

Stack* createStack(){
    Stack*stack = (Stack*)malloc(sizeof(Stack));
    stack->top=NULL;
    return stack;
}
void push(Stack*stack,int val){
    struct Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->val=val;
    newNode->next=stack->top;
    stack->top=newNode;
   
}

int pop(Stack*stack){
if(stack->top==NULL){
    printf("stack is empty");
    return -9999;
}
Node*temp=stack->top;
int popval=temp->val;
stack->top=stack->top->next;
free(temp);
return popval;

} 
int peek(Stack *stack){
    if(stack->top==NULL){
        printf("stack is empty");
return -9999;
    }
    return stack->top->val;
}
int main() {
    Stack* myStack = createStack();

    push(myStack, 10);
    push(myStack, 20);
    push(myStack, 30);

    printf("%d\n", peek(myStack)); 

    printf("%d\n", pop(myStack));  
    printf("%d\n", pop(myStack));  

    printf("%d\n", peek(myStack)); 

    return 0;
}

