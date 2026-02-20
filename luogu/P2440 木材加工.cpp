#include<iostream>

using namespace std;
const int N = 1e5 + 10;
int a[N];
int n;//原木数量 
int k;//需要最小段的数量
	bool check(int mid){
	int cal = 0;
	for(int j = 1; j <= n; j++){
		cal += a[j] / mid;
	}
	if(cal >= k)return true;	
	else return false; 
}
	
int main(){
	
	cin>>n;

	cin>>k;
	for(int i=1; i <= n; i++){
		cin>>a[i];
	} 
	long long left = 0;
	long long right = 1e8;
	long long mid;
	

	while(left < right){
		mid = left + (right - left + 1)/2;
		
		if(check(mid)){
			left = mid;
		}
		else right = mid - 1;
	}
	cout<<left;
	return 0;
} 