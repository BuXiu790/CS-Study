#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>



  struct ListNode {
      int val;
      struct ListNode *next;
  };
 
bool hasCycle(struct ListNode *head) {
    struct ListNode*slow=head;
    struct ListNode*fast=head;
    while(fast->next!=NULL&&fast!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(fast==slow){
            return 1;
        }
      

    }
return 0;



    
}