#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
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

char* removeDuplicates(char* s){
    Stack*stack=createStack();
    int i=0;
    while(s[i]!='\0'){
        char c=s[i];
        if(stack->top==NULL){
            push(stack,s[i]);
        }
        else{
           if(peek(stack)==c){
            pop(stack);
           } 
           else{
            push(stack,c);
           }
        }
        i++;
    }
    int len = strlen(s);
    char *result =(char*)malloc(sizeof(char)*(len+1));
    int court =0;
    while(stack->top!=NULL){
        //result在堆内存申请了空间，所以可以更改，可以读写
        result[court++]=pop(stack);
    }
    result[court]='\0';

    //现在要反转字符串
    //双指针旋转法
    int left =0;
    int right =court-1;
    while(left<right){
        char temp =result[left];
         result[left]=result[right];
         result[right]=temp;
         left++;
         right--;

    }
    free(stack);
    return result;

   


}