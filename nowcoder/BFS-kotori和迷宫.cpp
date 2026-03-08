#include<iostream>
#include<queue>
using namespace std;
const int N =100;
char x[N][N];
int vis[N][N];
int ans = 0;
int ret = 999999;
int step = 0;
//方向数组 
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int a,b; 
void bfs(){
	queue<pair<int,int>> q;
	q.push({a,b});
	while(!q.empty()){
		auto item = q.front();
		q.pop();
		//尝试四个方向 
		for(int i = 0; i < 4;i++){
			int nx = item.first + dx[i];
			int ny = item.second + dy[i];
			if(vis[nx][ny] != 0)continue;
			if(x[nx][ny] == 'e'){
				vis[nx][ny] = vis[item.first][item.second] + 1;
				ans++;
				ret = min(vis[nx][ny],ret);
			}
			if(x[nx][ny] == '*')continue;
			if(x[nx][ny] == '0')continue;
			if(x[nx][ny] == '.'){
				q.push({nx,ny});
				vis[nx][ny] = vis[item.first][item.second] + 1;
			}
			
		}
	}
	
}
int main(){
	int n,m;
	cin >> n >> m;
	//n行m列
	for(int i =1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cin >> x[i][j];
			if(x[i][j]=='k'){
			a=i;
			b=j;
			}

		}
	}
	bfs(); 
if(ret == 999999){
	cout<<"-1";
}
else{
	cout<<ans<<" "<<ret;
}	
	 
	
	return 0;
}