#include<stdio.h>
#include<stdlib.h>
  struct ListNode {
      int val;
      struct ListNode *next;
 };
 
struct ListNode* middleNode(struct ListNode* head) {
    struct ListNode* slow=head;
    struct ListNode* fast=head;
    while(fast==NULL&&fast->next==NULL){        
        fast=fast->next->next;
        slow=slow->next;
        
    }
     return slow;
}