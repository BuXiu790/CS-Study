#include<iostream>
using namespace std;
const int N = 2e5 + 20;
int parent[N];
//并查集
 
 //初始化
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

int main(){
	ios::sync_with_stdio(false);
    cin.tie(0);
    
    int n,m;
    cin >> n >> m;
    
    init(n);
    
    int z,x,y;
    for(int i = 1; i <= m; i++){
    	cin >> z >>x >>y;
    	if(z == 1) join(x,y);
    	else{
    		if(find(x) == find(y)){
    			cout<<"Y\n";
			}
			else{
				cout<<"N\n";
			}
		}
	} 
	
	return 0;
}