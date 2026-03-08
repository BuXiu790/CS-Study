#include<iostream>
#include<cstring>
using namespace std;

const int N = 100;
int A[N], D[N], L[N];
bool vis[N]; 
bool j = false; 

// 【改变 1】：增加一个参数 time，记录当前跑道空闲出来的时间
void dfs(int step, int K, int time){
	// 剪枝 1：如果别的平行宇宙已经成功了，直接收工
	if(j == true) return;
	
	// 【改变 2】：能活着走到这里，说明前面所有的飞机都安全降落了！
	// 不需要再去 for 循环验尸了，直接宣布胜利！
	if(step >= K){
		j = true;
		return;		
	}

	for(int i = 1; i <= K; i++){
		if(vis[i] == true) continue;
		
		// ==========================================
		// 【核心剪枝 2】：登机前安检！
		// 如果这架飞机等不到现在的 time 就已经坠毁了，
		// 直接放弃它，去试下一架飞机！(这就是剪枝的威力)
		// ==========================================
		if(time > A[i] + D[i]){
			continue; 
		}
		
		// 如果没坠毁，就算一下这架飞机降落后，跑道的新时间
		int next_time = 0;
		if(time > A[i]){
			next_time = time + L[i];
		} else {
			next_time = A[i] + L[i]; // 你的优雅等式
		}
		
		// 做出选择
		vis[i] = true;
		
		// 【改变 3】：把更新后的 next_time 传给下一层！
		dfs(step + 1, K, next_time);
		
		// 回溯，撤销选择
		vis[i] = false;
	}
}

int main(){
	int T;
	cin >> T;
	for(int t = 1 ; t <= T; t++){
		int K;
		cin >> K;
		memset(vis, 0, sizeof(vis));
		for(int i = 1; i <= K; i++){
			cin >> A[i] >> D[i] >> L[i];
		}
	
		j = false;
	 
		// 初始状态：第 0 架飞机，跑道从 0 时刻开始空闲
		dfs(0, K, 0);
		
		// 检查最终结果
		if(j == true) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
	return 0;
}