#include<iostream>
using namespace std;
typedef long long ll;
ll qpow(ll a, ll b ,ll p){
	ll ret = 1;
	while(b){
		if(b & 1) ret = a * ret % p;
		a = a * a % p;
		b >>= 1;
	}
	return ret;
}
int main(){
	ll a,b,p;
	cin >> a >> b >>p;
	ll sum = qpow(a,b,p);
	cout<<a<<"^"<<b<<" mod "<<p<<"="<<sum;
	return 0;
} 