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
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    struct ListNode *pa=headA;
    struct ListNode *pb=headB;
    while(pa!=pb){
        pa=(pa==NULL?headB:pa->next);
        pb=(pb==NULL?headA:pb->next);
    }
    return pa;
}