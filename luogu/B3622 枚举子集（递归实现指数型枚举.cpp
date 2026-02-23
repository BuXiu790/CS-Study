#include<iostream> 
using namespace std;
const int K = 100;
string a[K];
int n;
void dfs(int step){
	//截止条件
	if(step > n){
	for(int i = 1; i <= n; i++ ){
		cout<<a[i];
	}
	cout<<endl;
	return;
	} 
	
	a[step] = "N";
	dfs(step + 1);
	a[step] = "Y";
	dfs(step + 1);
	
}


int main(){
	
	cin>>n;
	dfs(1) ;
	
	
	
	return 0;
}