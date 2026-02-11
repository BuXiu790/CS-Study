#include<iostream>
using namespace std;
// 1保存副本：int key=a[i]; —— 这一步最关键，因为如果不存下来，
// 后面 a[j+1]=a[j] 覆盖的时候，原本的数据就丢了。
// 2挪位逻辑：a[j+1]=a[j]; 
// —— 这就是“把椅子往后移”的动作，非常精准。
// 3落座时机：a[j+1]=key; —— 循环结束时，j 会多减一次
// （变成 -1 或者指向了一个比 key 小的数），所以空位确实是在 j+1


void insert_sort(int a[],int N){
	for(int i=1;i<N;i++){
		int key=a[i];
		int j=i-1;
		while(j>=0 && a[j]>key){
		a[j+1]=a[j];
		j--;
		}
		a[j+1]=key;
	}
}


int main() {
   
    const int N = 10;
    int a[N] = {5, 2, 9, 1, 5, 6, 0, 4, 3, 8};

    cout << "排序前: ";
    for(int i = 0; i < N; i++) cout << a[i] << " ";
    cout << endl;

   
	insert_sort(a, N);

    
    cout << "排序后: ";
    for(int i = 0; i < N; i++) cout << a[i] << " ";
    cout << endl;

    return 0;}