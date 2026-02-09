#include<iostream>
using namespace std;
int map[5][4] = {
    {0, 0, 1, 0},
    {0, 0, 0, 0},
    {0, 0, 1, 0},
    {0, 1, 0, 0},
    {0, 0, 0, 1}
};
int book[50][50];
int min_step=999999;
int m=4;
int n=3;//终点4，3 
void dfs(int x,int y,int step){
	//截止条件
	if(x==m&&y==n) {
		if(step<=min_step){
			min_step=step;
		}
		return ;
	}
	//选择方向
	int next[4][2]={{0,1},{1,0},{-1,0},{0,-1}} ;
	for(int i=0;i<=3;i++){
		int dx=x+next[i][0];
		int dy=y+next[i][1];
		//越界判断,障碍判断 
		if(dx<5&&dy<6&&dx>=1&&dy>=1&&book[dx][dy]==0&&map[dy-1][dx-1]==0){
			book[dx][dy]=1;
			dfs(dx,dy,step+1);
			book[dx][dy]=0;
		}
			
		}
		
		
	}
	int main(){
		book[0][0]=1;
		dfs(1,1,0);
		cout<<min_step;
	}
	
