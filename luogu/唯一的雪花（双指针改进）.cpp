#include<map> 
#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
const long long Q = 1e9 +10;
long long arr[100005];
long long arr2[100005];
int main(){
	int T;//每组数据
	cin>>T;
	 for(int i = 1; i <= T; i++){
	 	int count = 0;
	 	int themax = -1;
	 	int n;
	 	cin>>n;
	 	for(int k = 1; k <= n; k++){
	 		cin>>arr[k];
		 }//输入完成这一组所有雪花 
		 //初始化 
		int right = 1, left = 1, ret = 0;
		map<int,int> mp;		
		while(right<=n){
			//进窗口 
		mp[arr[right]]++;
		//判断一下	
			while(mp[arr[right]]>1){
				//出窗口 
				mp[arr[left]]--;
				left++;
			
			}
			//窗口合法，更新结果 
			ret=max(ret,right-left+1);
			right++;
		}	
		cout<<ret;	
	}
		
		
}
	 	
	 
	 
	
	
	
	
 