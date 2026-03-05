#include<iostream>
#include<deque>
const int N = 1e6 + 10;
long long a[N];
long long maxval[N] ;
long long minval[N];
using namespace std;
int main(){
	int n;//长为n
	int k;//大小为k的窗口
	cin>>n>>k;
	deque<int> q;
	deque<int> q2;
	 for(int i = 1; i <= n; i++){
	 	//处理输入 
	 	cin>>a[i];
	 	//求最大值 
	 	while(!q.empty() && a[q.back()] <= a[i]){
	 		q.pop_back();
		 }
	 	q.push_back(i);
		if(q.back() - q.front() + 1 > k) q.pop_front();	
		if(i>=k) maxval[i] = q.front();
		
		//求最小值 
		 	while(!q2.empty() && a[q2.back()] >= a[i]){
	 		q2.pop_back();
		 }
	 	q2.push_back(i);
		if(q2.back() - q2.front() + 1 > k) q2.pop_front();	
			if(i>=k) minval[i] = q2.front();
			
	 }
	 
	 	for(int i = k ; i <= n; i++){
	 	cout<<a[minval[i]]<<" ";
	 }
	 	 cout<<"\n";
	 for(int i = k ; i <= n; i++){
	 	cout<<a[maxval[i]]<<" ";
	 }


	 
	 return 0;
}

	

	 	
	 	
	
	 
	 
	 
