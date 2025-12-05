/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

  struct ListNode {
      int val;
     struct ListNode *next;
  };
bool isPalindrome(struct ListNode* head) {
     struct ListNode *fast=head;
      struct ListNode *slow=head;
       struct ListNode *prev=NULL;
        struct ListNode *curr=head;
         struct ListNode *next=head;
         //找中点
     while(fast!=NULL&&fast->next!=0){
        slow=slow->next;
        fast=fast->next->next;
     }    
    curr=slow;
    next=curr->next;
    //反转链表
     while(curr!=NULL){
         next=curr->next;
        curr->next=prev;
        prev=curr;
        curr=next;
       
     }
     //比较逻辑
     curr=prev;
     while(curr!=NULL){
        if(curr->val==head->val){
            curr=curr->next;
            head=head->next;

        }
        else{
            return 0;
        }
     }
     return 1;

}