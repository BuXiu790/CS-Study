#include<iostream>
using namespace std;
//从第一个数开始，两两比较。如果你比右边的邻居大，你俩就交换位置。 
//这样一轮下来，最大的那个数肯定会被一路交换，直到被挤到数组的最后面。
void bubble_sort(int a[],int N){
 	for(int i=0;i<N-1;i++){
 		bool swapped=false;
 		for(int j=0;j<N-1-i;j++){
 			if(a[j]>a[j+1]){
 				swap(a[j],a[j+1]);
 				swapped=true;
			 }
		 }
		 if(swapped==false){
		 	break;
		 }
	 }
}



int main() {
   
    const int N = 10;
    int a[N] = {5, 2, 9, 1, 5, 6, 0, 4, 3, 8};

    cout << "排序前: ";
    for(int i = 0; i < N; i++) cout << a[i] << " ";
    cout << endl;

   
	bubble_sort(a, N);

    
    cout << "排序后: ";
    for(int i = 0; i < N; i++) cout << a[i] << " ";
    cout << endl;

    return 0;}