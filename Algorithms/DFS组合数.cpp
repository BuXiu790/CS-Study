//现在我们要挑战 组合： 从 1~5 中选 3 个数，不考虑顺序
//（1 2 3 和 3 2 1 算同一种，只输出 1 2 3）。
//这就要求：后面的数必须比前面的大！ 
//(你选了 1，后面只能选 2,3,4,5；你选了 3，后面只能选 4,5；绝不能回头选 1)。
#include<iostream>
using namespace std;
int a[100];
int m; //选几个数 
int n;//一共有几个数 
void dfs(int step, int start){
	if(step>=m+1){
		for(int i=1;i<=m;i++){
			cout<<a[i];
		}
		cout<<endl;
		return ; 
	}
	for(int i=start;i<=n;i++){
		a[step]=i;
		dfs(step+1,i+1);
		// 但是 for 循环并没有结束！
        // 程序会自动执行 i++ (尝试下一个数)
        // 这就相当于：“刚才选了 i，现在我不选 i 了，我要改选 i+1”
        // 这就是回溯的本质：撤销选择，尝试下一个。
	}
	
} 