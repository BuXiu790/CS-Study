#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void  generataData(int *arr,int n){
    int *p;
    for(p=arr;p<arr+n;p++){
        *p=rand()%100+1;

    }
}
void print(int *arr,int n){
for(int i=0;i<n;i++){
    printf("%d ",*(arr+i));
}
printf("\n");
}
void select(int *arr,int n){
    int *i,*j,*min;
    int temp;
    for(i=arr;i<arr+n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(*j<*min){
               min=j;
            }
        }
        if(min!=i){
            temp=*i;
            *i=*min;
            *min=temp;
        }


    }


}
#define N 20
int main(){
    int arr[20];
    srand((unsigned)time(NULL));
    generataData(arr,N);
    print(arr,N);
    select(arr,N);
    print(arr,N);

}