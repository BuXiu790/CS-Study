#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
const int N = 110;
int x[N];
int y[N];
bool vis[N];
double dist[N];
vector<int> graph[N];

void dijstra(int s){
	priority_queue<pair<double,int> ,vector<pair<double,int>> ,greater<pair<double,int>> > pq;
    //把距离近的放前面 
	pq.push({0,s});

for (int i = 0; i < N; i++) dist[i] = 1e9;
	dist[s] = 0;
	while(!pq.empty()){
		auto item = pq.top();
		pq.pop();
		double dist2 = item.first;
		int index = item.second;//得到元素下标
		if(vis[index]) continue;
        //出栈的元素一定找到了最小的距离
		vis[index] = true;
		for(auto it  : graph[index]){
			double dx = x[it] - x[index];
			double dy = y[it] - y[index];
			double squre_distance = dx * dx + dy * dy;
			double distance = sqrt(squre_distance);
			if(dist[it] > dist2 + distance){
				dist[it] = dist[index] + distance;
				pq.push({dist[it],it});//改变了距离的元素入栈
			}
		}
	}
	
}
int main(){
	int n,m;
	cin >> n;
	for(int i =1; i <= n; i++){
		cin>> x[i] >> y[i];	
	}
	cin >> m;
	for(int i = 1; i <= m; i++){
		int u ,v;
		cin >> u >> v; 
        //记录每个点能去哪
		graph[u].push_back(v);
		graph[v].push_back(u);
		
	}
	int s, t;
	cin>>s >>t;
	dijstra(s);
	printf("%.2f",dist[t]);
	return 0;
}