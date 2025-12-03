
#include <stdlib.h>
#include<stdio.h>
struct ListNode {
    int val;
    struct ListNode *next;
};
struct ListNode* removeElements(struct ListNode* head, int val) {
    //虚拟头节点
struct ListNode* dummy = (struct ListNode*)malloc(sizeof(struct ListNode));
dummy->next = head; 
struct ListNode* current=dummy;
while(current->next!=NULL){
    if(current->next->val==val){
        //temp临时存储需要删掉的节点
      struct ListNode* temp=current->next;
      current->next=current->next->next;
      free(temp);

    }else{
    current=current->next;}
}
//不要忘记释放dummmy
struct ListNode*newhead=dummy->next;
free(dummy);
return newhead;
//test
}