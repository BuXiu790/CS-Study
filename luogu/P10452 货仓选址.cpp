#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int main(){
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int sum = 0;
	for(int i = 1; i <= n; i++){
		sum +=abs(a[i]-a[n/2]);
	}
	cout<<sum;
	return 0;
} 