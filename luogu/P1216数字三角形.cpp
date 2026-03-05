#include<iostream>
using namespace std;
const int N = 1100;
int f[N][N];
int a[N][N];
//走到fn,有几种走法 
int main(){
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= i; j++){
			cin>>a[i][j];
			
			f[i][j] = max(f[i-1][j-1],f[i-1][j]) + a[i][j];
		}	
	}
	int ret = 0;
	for(int i =1; i <= n; i++){
		ret = max(ret,f[n][i]);
	}
	cout<<ret;
	return 0;
}