#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
using namespace std;
const int N =  2e5 + 10;
    int n,m,s,u,v,w;
    //最短距离 
    int dist[N];
    //标记这个点有没有找到最短路 
    bool vis[N];
vector<pair<int,int>>  graph[N];
void dijkstra(int s){
    //创建自动把最短路径排到top的优先队列
     priority_queue<pair<int,int> ,vector<pair<int,int>>,greater<pair<int,int>> > pq;

	  dist[s] = 0;//到出发点的距离为0
	  pq.push({0,s});//第一个元素是到此地的代价，第二个是此地 
	  while(!pq.empty()){
	  	auto item = pq.top();
	  	pq.pop();
	  	int d = item.first;//到达这个地点代价 
	  	int u = item.second;//当前弹出来的地点 
	  	if(vis[u])continue;//已经找到最短路的地点不再检查

        //dijkstra每次出栈的位置一定能找到最短路
	  	vis[u] = true;

        //graph[u]存着u地能通往哪些地方，以及距离
	  	for(auto edge :graph[u] ){
            
	  		 int v = edge.first;//邻居
			 int w = edge.second;//代价 


			 if(dist[v] > dist[u] + w){
                //出栈的节点有更短的路通向邻居v
                //更新v的最短距离，并入栈v
			 	dist[v] = dist[u] + w;
			 	pq.push({dist[v],v});
			 }
			 
			 
		  }
	  	
	  }
	  
    }

int main(){

      cin >> n >> m>> s;
 	 // s表示出发点
    //n个点，m条边
    for(int i = 1; i <= m; i++){
        cin >> u >>v >> w;
        graph[u].push_back({v,w});
        //u号地点到达v地需要w
        
    }
    memset(dist,0x3f,sizeof(dist));
    dijkstra(s);
	for(int i =1 ; i<=n; i++ ){
		cout<<dist[i]<<" ";
	}
 	cout<<endl;
    
    return 0;
}