// 题目： 小蓝要在 1 到 2023 中，找到所有满足下面条件的数： 这个数本身，和它除以 2 之后的数，求和 后是一个 平方数。

// 解释： 假设这个数是 x。 条件是：x + (x / 2) 的结果必须是一个完全平方数（比如 1, 4, 9, 16, 25...）。 注意：这里是整数除法，比如 5/2 = 2。

// 请问：1 到 2023 中有多少个这样的数？


#include<iostream>
#include<cmath>
using namespace std;
int  main(){
	static int count=0;
	for(int x =1;x<=2023;x++){
		int k=x/2;
		int sum=x+k;
		
		int root=sqrt(sum);
		if(root*root==sum){
		 count++;
		}
		
	}
	cout<<count<<endl;
} 