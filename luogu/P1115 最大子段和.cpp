#include<iostream>
using namespace std;

const int N =1e6+10;
long long a[N],f[N];
int main(){
	int n;
	cin>> n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	//算出前缀和 
	for(int i=1;i <= n; i++){
		f[i]=f[i-1]+a[i];
	}
	long long themax=-1e20;
	long long prevmin= 0;
	for(int i=1; i <= n;i++){
	themax= max(themax,f[i]-prevmin);
	prevmin=min(prevmin,f[i]);	
	}
	cout<<themax;
	
	return 0;
}
	 
	
