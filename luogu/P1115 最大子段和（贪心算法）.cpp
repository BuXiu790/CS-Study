#include<iostream>
using namespace std;
const int N = 2e5 + 10;
long long a[N];
int main(){
	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}

	int sum = 0;
	int ret = -1e6;
	for(int i = 1; i <= n; i++){
		sum +=a[i];
		ret = max(ret,sum);
		if(sum < 0){
			sum = 0;
		}
		
	}
	cout<<ret;
	
	
	return 0;
}

