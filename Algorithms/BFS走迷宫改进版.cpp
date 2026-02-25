#include<iostream>
using namespace std;
#include<queue> 

class Node{
	public:
		int r,c,step;
};

int n,m;
int map[55][55];
int vis[55][55];
int start_r,start_c,end_r,end_c;
int nextmove[4][2]={{0,1},{1,0},{-1,0},{0,-1}};

void bfs(){
	queue<Node> q;
	
	q.push({start_r,start_c,0});
	vis[start_r][start_c]=1;
	while(!q.empty()){
		Node cur=q.front();
		q.pop();
		if(cur.r==end_r&&cur.c==end_c){
			cout<<cur.step;
			return;
		}
		for(int i=0;i<4;i++){
			int nr=cur.r+nextmove[i][0];
			int nc=cur.c+nextmove[i][1];
			if(nr>=1&&nc>=1&&nr<=n&&nc<=m){
				if(map[nr][nc]==0&&vis[nr][nc]==0){
					vis[nr][nc]=1;
					q.push({nr,nc,cur.step+1});
				}
			}
		}
	}
}
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>map[i][j];
		}
	}
	cin >> start_r >> start_c >> end_r >> end_c;
	bfs();
	return 0;
}