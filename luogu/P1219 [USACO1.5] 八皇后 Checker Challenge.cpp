#include<iostream>
#include<vector>
using namespace std;
const int N =40;
int n;

bool vis_col[N];
bool vis_diag1[N];
bool vis_diag2[N];
vector<int> b;
int ans =0;



void dfs(int step,int ceng){
	if(step >= n){
		ans++;
		if(ans <= 3){
			for(auto x:b){
			cout<<x<<" ";
			
		}
		cout<<endl;
		}
		
	}
	for(int c = 1; c <= n;c++ ){
        //棋盘的数学规律
        //左上到右下，坐标差值相等
        //右上到左下，坐标和相等
	if(vis_col[c] || vis_diag1[ceng + c] || vis_diag2[ceng - c + n]){
		continue;
	}

        vis_col[c] = 1;
        vis_diag1[ceng + c] = 1;
        vis_diag2[ceng - c + n] = 1;
        b.push_back(c); // 记录路径
        
        dfs(step+1,ceng + 1);
        
		//回溯 
        b.pop_back();
        vis_col[c] = 0;
        vis_diag1[ceng + c] = 0;
        vis_diag2[ceng - c + n] = 0;
}

}
int main(){
	
	cin >> n;
	 dfs(0,1);
	 cout<<ans; 
	return 0 ;
} 