#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
	int x,y;
const int N =2e5 + 20;
int vis[N];
 
void bfs(){
	queue<int> q;
	q.push(x);
	vis[x] = 0;
	while(!q.empty()){
		auto cx = q.front();
		if(cx == y){
			cout<<vis[cx]<<endl;
			break;
		}
		q.pop();
		int ax = cx -1;
		if(ax >= 0 && ax < N&& vis[ax] == -1 ){
			vis[ax] = vis[cx] + 1;
			q.push(ax);
		}
		
		int bx = cx + 1	;
		if(bx >= 0 && bx < N &&vis[bx] == -1 ){
			vis[bx] = vis[cx] + 1;
			q.push(bx);
		}
		
		int dx = cx * 2	;
		if(dx >= 0 && dx < N && vis[dx] == -1 ){
			vis[dx] = vis[cx] + 1;
			q.push(dx);
		}
				
			
	}
}

int main(){
	int t;
	cin >> t;
	for(int k = 1; k <= t; k++){
		cin>>x>>y;
		memset(vis,-1,sizeof(vis)) ;
		bfs();
	}
	return 0;
}