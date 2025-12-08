#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
// 定义节点
typedef struct Node{
    int val;
    struct Node*next;
}Node;
//定义栈
typedef struct Stack{
struct Node* top;
}Stack;
//初始化创建栈
Stack* createStack(){
    Stack*stack=(Stack*)malloc(sizeof(Stack));
    stack->top=NULL;
    return stack;
}

//进栈
void push(Stack* stack,int val){
    Node*newNode=(Node*)malloc(sizeof(Node));
    newNode->val=val;
    newNode->next=stack->top;
    stack->top=newNode;
}

//出栈
int pop(Stack*stack){
    if(stack->top==NULL){
        printf("error,stack is empty");
        return -9999;
    }
    Node*temp=stack->top;
    int val=temp->val;
    stack->top=stack->top->next;
    free(temp);
    return val;
    
}
//peek函数
int peek(Stack*stack){
    if(stack->top==NULL){
        return -9999;
    }
    return stack->top->val;
}

//区分等级函数
int getrank(char op){
    if(op=='*'||op=='/')return 2;
    if(op=='+'||op=='-')return 1;
    return 0;
}


//中缀转后缀
void transform(char* s){
    int i=0;
    Stack* stack=createStack();
    while(s[i]!='\0'){
    
    
   if(s[i]>='0'&&s[i]<='9'){
    while(s[i]>='0'&&s[i]<='9'){
    printf("%c",s[i]);
    i++;
}
 printf(" ");
   //循环后会导致i多移动了一位
   i--;
   }  
else if(s[i]>='A'&&s[i]<='Z'){
    printf("%c ",s[i]);
}
//遇到符号
else if(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'){
    //检查 stack->top != NULL，且栈顶不是左括号
    while(stack->top!=NULL&&peek(stack) != '('&&getrank(peek(stack))>=getrank(s[i])){
        printf("%c ",pop(stack));
    } 
    push(stack,s[i]);
    
}
//遇到括号
else if(s[i]=='(')push(stack,s[i]);
else if(s[i]==')'){
while (stack->top != NULL && peek(stack) != '(') {
                printf("%c ", pop(stack));
            }
            pop(stack);
}
i++;
}
while (stack->top != NULL) {
        printf("%c ", pop(stack));
    }
    printf("\n");
    free(stack);


}
int main() {
    // 测试用例：多位数 + 字母 + 括号 + 优先级
    // 预期输出：10 20 A B - * + 
    char* s = "10+20*(A-B)";
    
    printf("中缀: %s\n", s);
    printf("后缀: ");
    transform(s); 
    
    return 0;
}
