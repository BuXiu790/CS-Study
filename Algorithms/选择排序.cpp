#include<iostream>
using namespace std;
//每次遍历选出最小的放在前面
//O(n^2)
void selection_sort(int a[],int N){
	
	for(int i=0;i<N-1;i++){
		int min_index=i;
		for(int j=i+1;j<N;j++){
			if(a[j]<a[min_index]){
				min_index=j;
				 
			}
		}
		if(i!=min_index){
			swap(a[i],a[min_index]);
		}
		
		
	}
}
int main() {
   
    const int N = 10;
    int a[N] = {5, 2, 9, 1, 5, 6, 0, 4, 3, 8};

    cout << "排序前: ";
    for(int i = 0; i < N; i++) cout << a[i] << " ";
    cout << endl;

   
    selection_sort(a, N);

    
    cout << "排序后: ";
    for(int i = 0; i < N; i++) cout << a[i] << " ";
    cout << endl;

    return 0;}