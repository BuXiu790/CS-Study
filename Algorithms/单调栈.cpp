#include<iostream>
#include<stack>
using namespace std;
const int N = 3e6 + 10;
int a[N];
int f[N];
//定义函数 f(i) 
//代表数列中第 i 个元素之后第一个大于 ai的元素下标 
//洛谷p5788
int main(){
	int n;
	cin>>n;
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	//栈存的是数组下标 
	stack<int> s;
	for(int i = n ; i>=1; i--){
		//倒序遍历 
		
	// 当栈顶元素小于等于当前元素
	//说明栈顶元素不是当前ai所求的下标，
	//也不会是ai之前的的元素所求的下标，所以出栈 
	while(!s.empty() && a[s.top()] <= a[i]) s.pop();
	
	//如果栈空了没找到，则不存在，返回0 
	if(s.empty()){
		f[i] = 0;
		
	} 
	else{
		//栈顶大于当前ai，则栈顶就是所求的下标 
		f[i] = s.top();
	} 
	//当前下标入栈 
	s.push(i);
}
	for(int i = 1; i <= n; i++){
		cout<<f[i]<<" ";
	}
	return 0;
}