#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int N =1e6;
 int parent[N];
 void init(int n){
 	for(int i = 1; i <= n; i++){
 		parent[i] = i;
	 }
 	
 } 

int find(int x){
	if(parent[x] == x) return x;
	int root = find(parent[x]);//找x的上级的根节点 
	
	parent[x] = root;//直接把x的上级定义为根节点 
	return root;
}

void join(int u, int v){
	//把v,u合并
	int rootv = find(v);
	int rootu = find(u);
	 if(rootu != rootv) {
        parent[rootu] = rootv; // 把u的根节点的上级设为v的根节点 
    }
} 
struct Edge{
	int u,v,w;
};

bool cmp(Edge a,Edge b){
	return a.w < b.w;
}

int main(){
	int n,m;
	cin >> n>>m;
	init(n);
	vector<Edge> edges;
	
	for(int i =0; i < m; i++){
		int u,v,w;
		cin >> u >> v >> w;
		edges.push_back({u,v,w});	
	}
	sort(edges.begin(),edges.end(),cmp);
	
	int total = 0;
	int edge = 0;
	for(int i =0; i < m; i++){
		int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].w;
		
		if(find(u) != find(v)){
			join(u,v);
			total += w;
			edge ++;
		}
		if(edge == n - 1) {
                break;
	}}
	//最小生成树最多只有n-1个边 
	if(edge == n - 1) {
        cout << total << "\n";
    } else {
        cout << "orz\n";
    }
	return 0;
}