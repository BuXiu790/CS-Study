#include<iostream>
using namespace std;
	const int N =1e5+10;
	 int a[N],b[N],g[N],k[N];
int main(){
	int n;//总共有多少地毯

	 cin>>n;
	
	 for(int i=1;i<=n;i++){
	 	 cin>>a[i]>>b[i]>>g[i]>>k[i];
		 //a,b分别是左下角x,y坐标
		 //g,k分别为在x方向y方向的长度
	 }
	 int x,y;
	 cin>>x>>y;//所求点
	 for(int i=n;i>=0;i--){
	 	if(i==0){
			cout<<-1;
			break;
		}
	 	if(x>=a[i]&&y>=b[i]&&x<=a[i]+g[i]&&y<=b[i]+k[i]){
	 		cout<<i;
			 break;
			 }
		}	 
	
	return 0;
}