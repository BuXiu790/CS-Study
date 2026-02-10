#include<iostream>
using namespace std;
//改进1：x，y改成row行，col列
//改进2：改为cin输入
//改进3；1-based，舍弃数组的0号索引 


int n,m;
int map[55][55];
int book[55][55];
int min_step=999999;
int start_r,start_c,end_r,end_c;

void dfs(int r, int c, int step){
	//截至条件 
	if(r == end_r && c== end_c){
		if(step < min_step){
			min_step=step;
		}
		return ;
		
	} 
	//如果已经大于最短路径了，就别跑了 
	if(step >= min_step)return;
	int next[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
	for(int i = 0;i < 4;i++){
		int nr=r+next[i][0];
		int nc=c+next[i][1];
	
		if (nr >= 1 && nr <= n && nc >= 1 && nc <=m){
		
			if(map[nr][nc] == 0 && book[nr][nc]==0){
			book[nr][nc] =1;
			dfs(nr,nc,step+1);
			book[nr][nc]=0;
		}
	}
	
}}
int main(){
		//n行m列 
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cin >> map[i][j];
			}
			
		}
		cin >> start_r >> start_c >> end_r >> end_c;
		book[start_r][start_c] = 1;
	dfs(start_r, start_c, 0);
	cout << min_step << endl;
	}  
	