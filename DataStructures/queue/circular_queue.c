#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAXSIZE 20

typedef struct{
    int *data;
    int size;
    int front;
    int rear;
    int capacity;
}CircularQueue;

//创建数组队列
CircularQueue* CreateQueue(int k){
    CircularQueue* q = (CircularQueue*)malloc(sizeof(CircularQueue));
    q->data=(int*)malloc(sizeof(int)*k);
    q->front=0;
    q->rear=0;
    q->capacity=k;
    q->size=0;
    return q;
}

bool enqueue(CircularQueue*q,int val){
    //判断栈是否满了
    if(q->size==q->capacity){
        return false;
    }
    q->data[q->rear]=val;
    q->rear=(q->rear+1)%(q->capacity);
    q->size++;
    return true;

}

bool dequeue(CircularQueue*q){
    //判断栈是否为空
    if(q->size==0){
        return false;
    }
    q->front=(q->front+1)%q->capacity;
    q->size--;
    return true;
}

//查看队头元素
int GetFront(CircularQueue* q){
    if (q->size == 0) return -1;
    return q->data[q->front];
}

//查看队尾元素
int GetRear(CircularQueue* q){
    if(q->size==0)return -1;
    return q->data[q->rear];
}

//test
int main() {
    // 1. 建一个只有 3 个位置的队列
    CircularQueue* q = CreateQueue(3);
    printf("Created a Queue with capacity 3\n\n");

    // 2. 入队 3 个人
    printf("Enqueue 10: %s\n", enqueue(q, 10) ? "Success" : "Fail");
    printf("Enqueue 20: %s\n", enqueue(q, 20) ? "Success" : "Fail");
    printf("Enqueue 30: %s\n", enqueue(q, 30) ? "Success" : "Fail");
    
    // 3. 试图入队第 4 个人 (应该失败)
    printf("Enqueue 40: %s\n", enqueue(q, 40) ? "Success" : "Full!");
    
    printf("\nCurrent Rear: %d\n", GetRear(q)); // 应该是 30
    printf("Current Front: %d\n\n", GetFront(q)); // 应该是 10

    // 4. 队头(10) 走了
    dequeue(q);
    printf("Dequeue one element.\n");
    printf("New Front: %d\n", GetFront(q)); // 应该是 20

    // 5. 刚才 40 没挤进来，现在有空位了，再试一次 (应该成功！且排在数组开头)
    printf("Enqueue 40 again: %s\n", enqueue(q, 40) ? "Success" : "Fail");
    printf("New Rear: %d\n", GetRear(q)); // 应该是 40

    return 0;}