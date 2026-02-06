//迷宫问题：给你一个地图，0 是路，1 是墙。
//你在起点 $(0, 0)$，终点在 $(4, 4)$。
//问：最少走几步能到终点？
#include<iostream>
#include <queue>
using namespace std;
class Point {
    public:
    int x;
    int y;
    int step; // 记录这是第几步走到的
};
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
// 1. 地图 (0是路, 1是墙)
int map[5][5] = {
    {0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0},
    {0, 0, 1, 1, 0},
    {0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0}
};
// 2. 标记数组 (记录走没走过)
int vis[5][5] = {0};
int main(){
    

    queue<Point> q;
    q.push({0,0,0});
    vis[0][0]=1;

    while(!q.empty()){
        Point head=q.front();
        q.pop();
        if(head.x == 4 && head.y == 4) {
            cout << "最少需要走: " << head.step << " 步" << endl;
            return 0;  
        }
        for(int i=0;i<4;i++){
            int nx =head.x+dx[i];
            int ny =head.y+dy[i];
            // A. nx, ny 不能越界 (必须在 0~4 之间)
            // B. map[nx][ny] 必须是 0 (是路)
            // C. vis[nx][ny] 必须是 0 (没走过
            if(nx >= 0 && nx < 5 && ny >= 0 && ny < 5 && map[nx][ny] == 0 && vis[nx][ny] == 0){

                vis[nx][ny]=1;
               q.push({nx,ny,(head.step)+1});
        } 

    }

}return 0;}