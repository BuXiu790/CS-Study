#include<iostream>
using namespace std;
#include<queue>
#include<vector>
#include<cstring>
const int N = 3e3 + 10;

int dist[N];
bool vis[N];//vis来表示此地点是否在队列中
int cnt[N];//步数 
vector<pair<int,int>> graph[N];
//s是起点，n来判断是否>=n 
bool SPFA(int n,int s){
	queue<int> q;
	q.push(s);//s表示起点 
	//vis来表示此地点是否在队列中 
	vis[s] = true;
	dist[s] = 0; 
	while(!q.empty()){
	int u = q.front();
	vis[u] =false;
	q.pop();

	
	for(auto edge : graph[u]){
		int v = edge.first;
		int w = edge.second;
		//松弛 
		if(dist[v] > dist[u] + w){
			dist[v] = dist[u] + w;
			//计步数 
			cnt[v] = cnt[u] + 1;
			
			if(cnt[v] >= n) {
                //SPFA遇到负环会不断绕圈
                //当计步器大于总城市时，判定有负数环
				return true;
			}
			
			if(vis[v] == false){
				//若v的路径变短且v没在队列
				//则把v push 
				vis[v] = true;
				q.push(v);
			}
		}
	}
		
		
	}
	return false; 
}
int main(){
	int T;
	cin >> T;
	int u,v,w;

	for(int k = 1; k <= T; k++){
		int n, m;
		cin >>n>>m;
		//每组测试重制结果 
		memset(dist,0x3f,sizeof(dist));
		memset(vis,0,sizeof(vis));
		memset(cnt,0,sizeof(cnt));
		for(int i = 1; i<=n;i++){
			graph[i].clear();
		}

        //输入数据
		for(int l = 1; l<= m;l++){
		cin >>u>>v>>w;
		graph[u].push_back({v,w});
		if(w>=0){
		graph[v].push_back({u,w});		
		}
	}

	if(SPFA(n,1)){
		cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	
	}
	
}