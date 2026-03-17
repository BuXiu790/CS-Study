#include<iostream>
#include<vector>
#include<queue>
using namespace std;
//dijkstra

const int N = 1010;
vector<pair<int,int>> graph_go[N];
vector<pair<int,int>> graph_back[N];//镜像图
int dist[N];

void dijkstra(int s,vector<pair<int, int>> graph[],int dist[]){
	priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>> > pq;
    //从小到大排序
	bool vis[N] ={false};
	pq.push({0,s});
    //初始化dist
	for (int i = 0; i < N; i++) {
        dist[i] = 1e9;
    }
	dist[s] = 0;
	while(!pq.empty()){
		auto item = pq.top();
		pq.pop();
		int d = item.first;
		int u = item.second;
		if(vis[u])continue;
		vis[u] = true;
		
		for(auto x : graph[u]){
			int v = x.first;
			int w = x.second;
			if(dist[v] > dist[u] + w) {
				dist[v] = dist[u] + w;
				pq.push({dist[v],v});
			}
		}
	}
}

int main(){
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int u,v,w;
		cin >> u >> v >> w;
		graph_go[u].push_back({v,w});
		graph_back[v].push_back({u,w});
	}
	int dist_go[N];
    int dist_back[N];
	dijkstra(1,graph_go,dist_go);
	dijkstra(1,graph_back,dist_back);
	long long total;
	for(int i = 2; i <= n; i++){
		total += dist_go[i] + dist_back[i];
	}
	cout<<total;
	return 0;
} 