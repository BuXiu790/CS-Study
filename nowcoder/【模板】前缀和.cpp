#include<iostream>
using namespace std;

const int N =1e5+10;
long long a[N],f[N] ,l[N],r[N];
int main(){
	int n,m;
	cin>>n>>m;
	//数组里有n个数
	//查询m次
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//处理数组输入
	//构造前缀和 
	for(int i=1;i<=n;i++){
		f[i]=f[i-1]+a[i];
	}
	
	for(int i=1;i<=m;i++){
		cin>>l[i]>>r[i];
		
	} 
	for(int i=1;i<=m;i++){
		cout<<f[r[i]]-f[l[i]-1]<<endl;
	} 
	return 0;	
	} 
	 
	
