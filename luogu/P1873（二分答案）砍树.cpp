#include<iostream>
using namespace std;
const int Q = 1e6 + 10;
typedef long long ll;
long long H[Q];
long long N , M ;
bool check(ll val){
	ll sum = 0;
	for(int i = 1; i <= N ;++i){
		
		if(H[i] >= val){
			sum += H[i] - val;
		}
	}
	if(sum >= M )return true;
	else{
		return false;
	}
}
int main(){
	 
	 cin >> N >> M ;
	 for(int i = 1 ; i <= N; ++i){
	 	cin >> H[i];
	 }
	 ll left = 0;
	 ll right = 2e9;
	 ll ans = 0;
	 ll mid;
	 while(left < right){
	 	mid = left + (right-left+1)/2;
	 	
	 	if(check(mid)){
	 		ans = mid;
	 		left = mid;
		 }else{
		 	right = mid - 1;
		 }
	 	
	 }
	 cout<<ans;
	return 0;
} 