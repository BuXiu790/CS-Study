#include<stdio.h>
#include <stdlib.h>
typedef int E;
typedef  struct node{
        E data;
        struct node*next;
    }Node,*pnode;
//初始化链表
void initialize(Node** head){
    *head=NULL;
    return;

}
//创建节点
Node* createNode(E data){
    Node* newnode=(Node*)malloc(sizeof(Node));
    if(newnode==NULL){
        printf("内存分配失败\n");
        exit(1);
    }
    newnode->data =data;
    newnode->next=NULL;
    return newnode;
}
//头插法
void insertHead(Node**head,E data){
    Node* newnode=createNode(data);
    newnode->next=*head;
    *head=newnode;
    return;
}
//尾插法
void insertTail(Node**head,E data){
    Node* newnode=createNode(data);
    if(*head==NULL){
        *head=newnode;

    }
    else{Node*current =*head;
        while(current->next!=NULL){
            current=current->next;
        }
        current->next=newnode;
    }
    return;
}

//选择位置插入节点
void insertpositision(Node** head, E data, int position){
    // 1. 处理头插情况
    if(position == 0){
        insertHead(head, data);
        return;
    }

  
    Node* current = *head;
    
    // 循环条件加一个 current != NULL，防止跑到 NULL 还要往后找，导致崩溃
    for(int i = 0; i < position - 1 && current != NULL; i++){
        current = current->next;
    }

    // 3. 检查位置是否合法
    // 如果 current 是 NULL，说明 position 远超链表长度
    if(current == NULL){
        printf("插入位置 %d 超出链表长度，插入失败\n", position);
        return; 
    }

    // 4. 位置合法，现在才开始造节点
    Node* newnode = createNode(data);

    newnode->next = current->next; 
    current->next = newnode;      
}
//打印链表
void printList(Node*head){
    Node*current =head;
    while(current!=NULL){
        printf("%d",current->data);
        current=current->next;
    }
    printf("\n");
    return;
}
void deleteNode(Node**head,int position){
    
    if(*head==NULL){
        return;
    }//链表为空
    if(position==1){
        Node*temp=*head;
        *head=(*head)->next;
        free(temp);
        return;
    }//链表为头节点
    Node*prev=*head;
    Node*current=(*head)->next;
    for(int i=1;i<position;i++){
        if(current==NULL){
            printf("error");
            return;
        }
        if(i+1==position){
            prev->next=current->next;
            free(current);
            return;
        }
        prev=prev->next;
        current=current->next;


    }


}



int main() {
  Node* head;
  initialize(&head );
  insertHead(&head,1);
  insertHead(&head,2);
  insertHead(&head,3);
  insertHead(&head,4);
  insertHead(&head,5);
  insertTail(&head,6);
  insertTail(&head,7);
  insertTail(&head,8);
  insertTail(&head,9);
  insertTail(&head,10);
  printList(head);




return 0;
}