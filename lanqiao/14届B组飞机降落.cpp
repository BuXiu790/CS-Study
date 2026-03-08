#include<iostream>
#include<cstring>
using namespace std;
const int N = 100;
int A[N],D[N],L[N];
bool vis[N] ;
int chose[N]; 
bool j = false ;
int ans;	
//枚举所有可能，再判断所有可能是否成立 
void dfs(int step,int K){
	//ans表示现在已经枚举了多少种可能 

	//剪枝 
	if(j == true) return;
	
	if(step >= K && j == false){
		ans++;
		//选了一次，检查这次能否降落成功 
		int time=0;
		//time表示现在的时间 
		for(int i = 0 ; i < step;i++){
			//判断这架能否成功降落 
			if(time >A[chose[i]] + D[chose[i]]){
				break;
			} 
			if(time > A[chose[i]]){
				time += L[chose[i]];
			}
			else{
				time += (A[chose[i]] - time) + L[chose[i]];
			}			
			if(i == step - 1){
				cout<<"YES"<<endl;
				//已经选出成功的结果 
				j = true;
			}
			
		}
		return ;		
	}



	for(int i = 1; i <= K; i++){
		if(vis[i] == true) continue;
		chose[step] = i;
		vis[i] = true;
		dfs(step +1,K);
		vis[i] = false;
	}
}
int main(){
	int T;
	cin >> T;
	for(int t = 1 ; t <= T; t++){
		int K;
		//有K架飞机 
		cin >> K;
		memset(vis,0,sizeof(vis));
		for(int i = 1; i <= K; i++){
			cin >> A[i] >> D[i] >> L[i];
			//A到达时间，D可盘旋时间，L降落时间 
		}
	
		//重制j 
		j =false;
	 
		dfs(0,K);
		if(j == false) {
            cout << "NO" << endl;
        }
	
		
		
	}
	return 0;
}