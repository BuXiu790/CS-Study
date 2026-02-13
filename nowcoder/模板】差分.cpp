#include<iostream>
using namespace std;

const int N =1e6+10;
long long a[N], f[N],ff[N];


const int q =1e6 +10;
int l[N],r[N],d[N];
int  main(){
	int n,q;
	cin>>n>>q;
	//n元素数量、q操作次数
	for(int i=1;i<=n;i++){
		cin>>a[i];
		
	}
	for(int i=1;i<=n;i++){
		f[i]=a[i]-a[i-1];
		//构造差分函数 
	}
	for(int i=1;i<=q;i++){
		cin>>l[i]>>r[i]>>d[i];
		//处理操作输入 
		f[l[i]] +=d[i];
		f[r[i]+1] -=d[i];
	}
	//差分数组求前缀和
	for(int i=1;i<=n;i++){
	ff[i]=f[i]+ff[i-1];
	} 
	for(int i=1;i<=n;i++){
		cout<<ff[i]<<" ";
	}
	return 0;
}
	
