#include<iostream>
using namespace std;
const int N = 1100;
int f[N];
int a[N][N];
//走到fn,有几种走法 
int main(){
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			cin>>a[i][j];
			
		}	
	}
	//空间优化 
	for(int i = 1; i <= n; i++){	
		for(int j = i; j >= 1; j--){
			f[j] = max(f[j-1],f[j]) + a[i][j];
		}
	}
	
	int ret = 0;
	for(int j = 1; j <= n; j++){
		ret=max(ret,f[j]);
	} 
	cout<<ret;
	return 0;
}