#include<iostream>
#include<cstring>
using namespace std;
const int N = 300;
int a[N][N];
int main(){
	int n,m;
	cin >> n >> m;//n个点m个边 
	int u,v,w;
	memset(a,0x3f,sizeof(a));
	for(int i = 0; i <= n; i++){
		a[i][i] = 0;
	}
	for(int i = 1; i <= m ; i++){
		cin >> u>> v>>w;
		a[u][v] = min(w,a[u][v]);//u->v花费w 
		a[v][u] = min(w,a[v][u]);
	} 
	for(int k = 1; k<= n; k++){
		//最外层循环,把每个位置当作中间点 
		for(int i = 1; i <= n; i++){
			//i起点
			for(int j = 1; j <= n; j++){
				//j终点 
				if(a[i][j] > a[i][k] + a[k][j] ){
					a[i][j] = a[i][k] +a[k][j];
				}
			} 
		} 
		
	}
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}