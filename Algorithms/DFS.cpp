#include<iostream>

using namespace std;
int n=4;
	int book[100]; 
	int a[100];

	int step=1;
	
void dfs(int step){
//截至条件
if(step==n+1) {
	for(int i=1;i<=n;i++){
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