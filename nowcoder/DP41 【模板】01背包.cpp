#include<iostream> 
#include<cstring>
using namespace std;

const int N = 1e3 + 10;
int dp[N];
int v[N];
int w[N];
int main(){
	int n,V;
	cin >> n >> V;
	for(int i = 1 ; i <= n ; i++){
		cin >> v[i] >> w[i];
	}
	
	for(int i = n; i >= 1 ; --i){
		for(int j = V; j >= v[i]; -- j){
			
				dp[j] =max(dp[j-v[i]] + w[i],dp[j]) ;
				
		}
				
	}
	cout<<dp[V]<<"\n";
	memset(dp,-0x3f,sizeof(dp));
	dp[0] = 0;
		for(int i = n; i >= 1 ; --i){
		for(int j = V;  j >= v[i]; -- j){
			if(j >= v[i]){
				dp[j] =max(dp[j-v[i]] + w[i],dp[j]) ;
			}	
		}
				
	}
	if(dp[V] < 0){
		cout<<0;
	}
	else{
		cout<<dp[V]<<"\n";
	}
	
	return 0;
}