#include<iostream>
using namespace std;
const int N = 11;
int a[N][N]; 
bool row[10][10]; 

bool col[10][10]; 

bool block[10][10];
//bool check(int x, int y, int val){
//	for(int i = 1; i <= 9; i++){
//		if(a[x][i] == val) return false;
//	}
//		for(int i = 1; i <= 9; i++){
//		if(a[i][y] == val) return false;
//	}
//	int sx = (x - 1) / 3 * 3 + 1;
//	int sy = (y - 1) / 3 * 3 + 1;
//	for(int i = sx; i <= sx + 2; i++){
//		for(int j = sy; j <= sy + 2; j++){
//			if(a[i][j] == val) return false;
//		}
//	}
//	return true;
//}
void dfs(int step){
	if(step >= 81){
		for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++){
			cout << a[i][j] <<" "; 
		}
		cout<<"\n";
		
	}
	exit(0);}
	int ix = step/9 + 1;
	int iy = step%9 + 1;
			if(a[ix][iy] != 0){
			dfs(step + 1);
			return ;
		}
		int b_num = (ix - 1) / 3 * 3 + (iy - 1) / 3;
	for(int i = 1; i <=9 ;i++){
if(!row[ix][i] && !col[iy][i] && !block[b_num][i]){
        
   
        a[ix][iy] = i;
        row[ix][i] = true;
        col[iy][i] = true;
        block[b_num][i] = true;
        
   
        dfs(step + 1);
        
     
        a[ix][iy] = 0;
        row[ix][i] = false;
        col[iy][i] = false;
        block[b_num][i] = false;
	}}
	 
}
int main(){
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++){
			cin >>a[i][j]; 
			if(a[i][j] != 0){
            int val = a[i][j];
           
            int b_num = (i - 1) / 3 * 3 + (j - 1) / 3; 
            
          
            row[i][val] = true;
            col[j][val] = true;
            block[b_num][val] = true;
		}
	}}
dfs(0);
}