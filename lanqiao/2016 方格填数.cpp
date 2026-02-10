#include<iostream>
using namespace std;
int map[3][4];
int dir[8][2] = {
    {1,0}, {-1,0}, {0,1}, {0,-1},
    {1,1}, {1,-1}, {-1,1}, {-1,-1}
};
int ans=0;
int book[10];

 bool check(int x,int y, int val){
 	for(int i=0;i<8;i++){
 		int nx=x+dir[i][0];
 		int ny=y+dir[i][1];
 		//nx有0，1，2三行 
 		//ny有，0,1,2,3四行 
 		if(nx>=0&&nx<3&&ny>=0&&ny<4){
 			if(map[nx][ny]==val+1||map[nx][ny]==val-1){
 				return false;
			 }
		 }
	 }
	 return true;
 }
 
 void dfs(int step){
 	//截止条件、
	 if(step==12){
	 	ans++;
	 	return ;
	 } 
	 int x=step/4;
	 int y=step%4;
	if( (x == 0 && y == 0) || (x == 2 && y == 3) ) {
        dfs(step + 1);
        return;}
	 for(int i=0;i<=9;i++){
	 	if(book[i]==0&&check(x,y,i)==true){
	 		book[i]=1;
	 		map[x][y]=i;
	 		dfs(step+1);
	 		book[i]=0;
	 		map[x][y]=-10;
		 }
	 }
	 
 	
 }
int main(){
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++){
			map[i][j]=-10;
		}
	}
	dfs(0);
	cout<<ans;
} 