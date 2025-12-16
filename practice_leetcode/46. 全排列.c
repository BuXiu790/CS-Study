#include<stdio.h>
#include<stdlib.h>
//nums数组
//numsize最大长度
//count当前数组的第几个
int* g_nums;       // 存原始数组
int g_numsSize;    // 存数组长度
int* g_path;       // 存当前结果
int* g_used;       // 存记账本
int** g_result;    // 存最终大仓库
int g_count;       // 存仓库里有几个结果了
void saveResult() {
    int* newRow = (int*)malloc(sizeof(int) * g_numsSize);
    
    for (int i = 0; i < g_numsSize; i++) {
        newRow[i] = g_path[i];
    }
    
   
    g_result[g_count] = newRow;
    
    g_count++;//仓库内存+1
}

void backtrack(int count) {
   if (count == g_numsSize) {
        saveResult(); 
        return;
    }
    for(int i = 0; i < g_numsSize; i++) {
        if(g_used[i] == 1) continue;

        g_used[i] = 1;
        g_path[count] = g_nums[i];

     
        backtrack(count + 1);
        //回溯撤销
        g_used[i] = 0;
        }}


int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
  
    g_nums = nums;
    g_numsSize = numsSize;
    
  
    g_path = (int*)malloc(sizeof(int) * numsSize);
    g_used = (int*)calloc(numsSize, sizeof(int));
    g_result = (int**)malloc(sizeof(int*) * 2000);
    g_count = 0;

   
    backtrack(0);
*returnSize = g_count;

  
    *returnColumnSizes = (int*)malloc(sizeof(int) * g_count);
    
    for (int i = 0; i < g_count; i++) {
        (*returnColumnSizes)[i] = numsSize;
    }
  
    return g_result;
}
