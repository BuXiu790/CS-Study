
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
		int maxlen = 0;
		for(int j = 1; j <= n; j++){
			for(int x = j; x <= n; x++){
				//窗口是起点j到x 
				bool is =false;
				for(int k = j; k < x; k++){
					if(arr[k]==arr[x]){
						is =true;
						break;
					}
				}
				// 如果发现重复，说明以 j 开头的这段最长只能到 x-1
				if(is) break;
				maxlen = max(maxlen, x - j + 1);
			}
		}
	 	
	 	cout<<maxlen; 
	 }
	
	
	
	
} 