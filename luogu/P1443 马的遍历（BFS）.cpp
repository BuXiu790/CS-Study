#include<iostream> 
#include<queue>
#include<cstring>
using namespace std;
 int n,m;
 const int N =600;
int x,y;
int map[N][N];
//方向数组 
	int dx[8] = {2,2,-2,-2,1,1,-1,-1};
	int dy[8] = {1,-1,1,-1,2,-2,2,-2};

class pos{
	public:
		int cx;
		int cy;
	
};

	void bfs(){
		queue<pos> q;
		q.push({x,y});
		map[x][y]=0;
		while(!q.empty()){
			//拿出头节点 
			auto t = q.front();
			q.pop();
			int x = t.cx;
			int y = t.cy;
			for(int i = 0; i < 8; i++){
				//尝试八个方向 
				int ix = x + dx[i];
				int iy = y + dy[i];
				//判断出界 
				if(ix < 1 || iy < 1 || ix > n || iy > m)continue;
				//判断是否走过 
				if(map[ix][iy]!= -1)continue;
				//计数 
				map[ix][iy] = map[x][y] + 1;
				//把新的位置压入队列 
				q.push ({ix,iy});
			}
			
		}
		
		
	}
int main(){
	cin>>n>>m;
	cin>>x>>y;


	memset(map,-1,sizeof(map));
	bfs();

	
	
	
	//输出结果 
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			cout<<map[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	return 0;
}