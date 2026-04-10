#include<iostream> 
using namespace std;
int n;
int a[10];
bool vis[10];
void dfs(int step){
	if(step == n){
		for(int i = 0 ; i < n; i++){
			printf("%5d",a[i]);
		}
		printf("\n");
		return ;
	}
	
	for(int i = 1 ; i <= n ; i++){
		if(vis[i]){
			continue;
		}
		vis[i] = true;
		a[step] = i;
		dfs(step+1);
		vis[i] = false;
		a[step] = 0;
	}
}

int main(){
	cin >> n;
	dfs(0);
	return 0;
}