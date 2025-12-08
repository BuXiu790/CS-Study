#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define elem char 
typedef struct Node{
    elem val;
    struct Node* next;
}Node;
typedef struct Stack{
    struct Node*top;
}Stack;
Stack* createStack(){
    Stack*stack=(Stack*)malloc(sizeof(Stack));
    stack->top=NULL;
    return stack;
}
void push(Stack* stack,elem val){
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->val=val;
    newNode->next=stack->top;
    stack->top=newNode;
}
elem pop(Stack*stack){
    if(stack->top==NULL){
        return -9999;
    }
    Node*temp=stack->top;
   elem num=stack->top->val;
   stack->top=stack->top->next;
   free(temp);
   return num;

  
}

bool isValid(char* s) {
    Stack*stack=createStack();
    
   for(int i=0;s[i]!='\0';i++){
    char c=s[i];
    if(c=='('||c=='['||c=='{'){
        push(stack,c);
    }
    else{
        if(stack->top==NULL){
            return false;
        }
        char c2=pop(stack);
        if(c2=='('&&c!=')'){
            return false; 
        }
        if(c2=='['&&c!=']'){
            return false;
        }
        if(c2=='{'&&c!='}'){
            return false;
        }
    }
   }
   if(stack->top==NULL){
    return true;
   }
   else{
    return false;
   }

    
}