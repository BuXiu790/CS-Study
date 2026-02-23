#include<iostream> 
#include<map>
#include<cmath>
using namespace std;
	int n,k;
	int ans = 0;
	int sum=0;
	const int N =1000;
	int a[N];
	int book[N];

bool is_prime(int sum){
	if(sum <= 1) return false;
	if(sum == 2) return true;
	if((sum%2)==0)return false;
	int sqrtnum = std::sqrt(sum);
	for(int i = 3; i <= sqrtnum; i += 2)
	if((sum%i) == 0)return false;
	return true;
}

	
	
	//A开始选数的位置，step现在选第几个数
    //k要选几个数
void dfs(int step,int A){
	if(step > k){
		if(is_prime(sum)){
			ans++;
			return; 
		}
		return;
	}
	
	for(int i = A; i <= n; i++){
		if( (k - step) > n - i) break;
		sum += a[i];
		dfs(step+1,i+1);
		//回溯 
		sum -= a[i];
		
	}
	
	
}



int main(){
	cin>>n>>k;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	
	dfs(1,1);
	cout<<ans; 
	return 0;
}

