#include<stdio.h>
#include<stdlib.h>
typedef struct ListNode{
    int val;
    struct ListNode* next;

}Node;
Node* delete(Node*head,int val){
    Node*dummy=(Node*)malloc(sizeof(Node));
    dummy->next=head;
    Node*current=dummy;
    while(current->next!=NULL){
        if(current->next->val==val){
            Node*temp=current->next;
            current->next=current->next->next;
            free(temp);
        }
        else{
        current=current->next;}
    }
    Node*newhead=dummy->next;
    free(dummy);
    return newhead;
    //////
}