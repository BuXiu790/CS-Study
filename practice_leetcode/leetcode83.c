/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include<stdio.h>
#include<stdlib.h>
struct ListNode {
      int val;
    struct ListNode *next;
  };
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode*curr=head;
   
    while(curr!=NULL&&curr->next!=NULL){
 if(curr->next->val==curr->val){
 struct ListNode*temp=NULL;
    temp=curr->next;
    
        curr->next=curr->next->next;  
        free(temp);
    }
    
    else{
        curr=curr->next;
    }}
    return head;
}