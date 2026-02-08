#include<iostream>
using namespace std;
int a[100];
int n=5;//1-5,5个数 
int k=10;//和等于10 
int m=3;//选3个数 

void dfs(int step,int start){
	if(step>=m+1){
		int sum=0;
		for(int i=1;i<=m;i++){
		 sum +=a[i];	
		}
		//判断和是否是k 
		if(sum==k){
				for(int i=1;i<=m;i++){
				//和是k，遍历打印
				cout<<a[i]<<" ";	
				}
				cout<<endl;
				return;
		}
		else{
			//和不是k 
			return;
		}
	}//截至条件if结束 
	for(int i=start;i<=n;i++){
		a[step]=i;
		dfs(step+1,i+1);
		
	}
	
	
	
}
int main(){
	dfs(1,1);
}