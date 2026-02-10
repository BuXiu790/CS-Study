//BFS 连通块 (Flood Fill)：
//main 循环遍历全图，找到新点调 bfs，
//bfs 负责把相连的区域全部标记 (vis=1)，不需要 step，也不需要 return

// 题目描述： 你有一张地图，字符 1 代表陆地，0 代表海洋
//。 陆地上下左右相连，构成一个 岛屿。

// 现在全球变暖，海平面上升。
// 规则： 任何一块陆地 (1)，如果它的 上下左右 只要有一个方向是海洋 (0)，它就会被淹没。
#include<queue>
#include<iostream> 
using namespace std;
class Node{
	public:
		int r,c;
};
int n;//行
int m;//列 
int map[55][55];
int vis[55][55];
int nextmove[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int flag=1;
void bfs(int r,int c){
	queue<Node> q;
	if(map[r][c] == 1 && vis[r][c] == 0){
		vis[r][c]=1;
	}
	q.push({r,c});
	while(!q.empty()){
		Node cur=q.front();
		q.pop();
		if(map[cur.r+1][cur.c]==1&&map[cur.r][cur.c-1]==1&&
		map[cur.r-1][cur.c]==1&&map[cur.r][cur.c+1]==1){
			flag=0;
		}
	for(int i=0;i<4;i++){
		int nr=cur.r+nextmove[i][0];
		int nc=cur.c+nextmove[i][1];
		if(nr>=1&&nc>=1&&nr<=n&&nc<=m){
			if(vis[nr][nc]==0&&map[nr][nc]==1){
				vis[nr][nc]=1;
				q.push({nr,nc});
			}
		}
	}
		
	}
	
}
int main(){
	int count=0;

int ans=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>map[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(map[i][j]==1&&vis[i][j]==0){
				count++ ;
				flag = 1;
					bfs(i,j);
					if(flag==0){
						flag=1;
						ans++;
					}
			}
		}
	}
	cout << count << endl;
	cout<<ans;
    return 0;
}