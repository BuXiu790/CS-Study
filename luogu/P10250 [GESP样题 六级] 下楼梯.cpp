#include<iostream>
using namespace std;
const int N = 100;
long long f[N];//走到fn,有几种走法 
int main(){
	int n;
	cin>> n;
	
	f[1] = 1;
	f[2] = 2;
	f[3] = 4;
	for(int i = 4; i <= n; i++){
		f[i]= f[i-1] + f[i-2] + f[i-3];
	}
	cout<<f[n];
	return 0;
}