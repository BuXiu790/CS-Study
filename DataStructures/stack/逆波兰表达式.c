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
//以上为栈的定义相关，以下为逆波兰表达式相关
//判断是不是加减乘除
bool isOp (char *s){
    return (s[1]=='\0'&&(s[0]=='+'||s[0]=='-'||s[0]=='*'||s[0]=='/'));
}
//逆波兰求值
int evalPRN(char* tokens[],int size){
    //创建栈
    Stack *stack=createStack();
    //遍历字符串并计算
   for(int i=0;i<size;i++){
    char* token=tokens[i];
    if(isOp(token)){
        int num2=pop(stack);
        int num1=pop(stack);
        if(token[0]=='+')push(stack,num1+num2);
        else if(token[0]=='-')push(stack,num1-num2);
        else if (token[0]=='*')push(stack,num1*num2);
        else if(token[0]=='/')push(stack,num1/num2);
    }
    else(push(stack,atoi(token)));

   }
   int result =pop(stack);
free(stack);
return result;
}
//test
int main() {
    
    char* tokens[] = {"2", "1", "+", "3", "*"};
    int size = 5;

    int result = evalPRN(tokens, size);
    
    printf("Result: %d\n", result); 
    return 0;
}
