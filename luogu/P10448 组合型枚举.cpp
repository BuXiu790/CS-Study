#include<iostream> 
#include<map>;
using namespace std;
int n,m;
const int A = 1000;
int a[A];
map<int,int> mp;
//多定义一个k，用来记录当前位置应该从哪开始选数
void dfs(int step,int k){
	//截至条件 
	if(step > m){
		for(int i = 1; i <= m; i++){
			cout<<a[i]<<" ";
		}
		cout<<endl;
		return;
	}
	
	for(int i = k;i <= n; i++){
		if(mp[i] >=1) continue;
        //m-step+1是剩余位置
        //n-i+1是剩余能选的数
		if((m-step ) > (n - i)) return; 

		a[step] = i;
        //记录这个数已经被选过了一次
		mp[i]++;
        //k=i+1表示下次从k+1处选数
		k = i + 1;
        
		dfs(step + 1,k);
        //清空这个位置的数，选其他数试试
		a[step] = 0;
		mp[i]--;
		
	}
	
	
	
}

int main(){
	cin>>n>>m;
	//n是总数，m是选出多少数 
	dfs(1,1);
	return 0;
} 