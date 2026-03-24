#include<iostream>
const int N =25;
long long f[N][N];
bool vis[N][N];
using namespace std;
int main(){
	int ix,iy,tx,ty;
	cin >> ix >> iy >> tx >> ty;
	vis[tx][ty] = true;//c
	if(tx-2 >= 0 && ty-1 >= 0){
	vis[tx-2][ty-1] = true;//p6	
	}
	if(tx-2 >= 0 ){
	vis[tx-2][ty+1] = true;//p7	
	}
	if(tx-1 >= 0 && ty -2 >=0){
		vis[tx - 1][ty - 2] = true;//p5
	}
	if(tx-1 >= 0){
		vis[tx - 1][ty + 2] = true;//p8
	}
	if(ty - 2 >= 0){
		vis[tx+1][ty-2] = true;
	}
	if(ty - 1 >= 0){
		vis[tx+2][ty-1] = true;
	}
	vis[tx+2][ty+1] = true;
	vis[tx+1][ty+2] = true;
	f[0][0] = 1;
	for(int j = 1; j <= iy; j++){
    if(vis[0][j] == true) {
        f[0][j] = 0;
    } else {
        f[0][j] = f[0][j-1];
    }
}
	for(int i = 1; i <= ix; i++){ 
    if(vis[i][0] == true) {
        f[i][0] = 0; 
    } else {
        f[i][0] = f[i-1][0]; 
    }}
	
	for(int i = 1;i <= 20; i++){
		for(int j = 1; j <= 20; j++){
			if(vis[i][j] == true){
				f[i][j]= 0;
				continue;
			}
			f[i][j] = f[i-1][j] + f[i][j-1];
		}
	}
	cout<<f[ix][iy];
	return 0;
}