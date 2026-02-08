#include<iostream>

using namespace std;
//从n个数里选出m个全排列 
int n=5;
int m=3;
	int book[100]; 
	int a[100];

	int step=1;
	
void dfs(int step){
//截至条件
if(step==m+1) {
	for(int i=1;i<=m;i++){
		cout<<a[i];
		
	
	}
	
	cout<<endl;
		return;
}

for(int i =1;i<=n;i++){
	if(book[i]==0){
		a[step] = i;
		book[i] =1;
		dfs(step+1);
		
		book[i]=0;
	}
}
 }
 int main(){
 	dfs(1);
 }