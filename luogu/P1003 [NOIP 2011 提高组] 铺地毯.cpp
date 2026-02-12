#include<iostream>
using namespace std;
	const int N =1e5+10;
	 int a[N],b[N],g[N],k[N];
int main(){
	int n;//总共有多少地毯

	 cin>>n;
	
	 for(int i=1;i<=n;i++){
	 	 cin>>a[i]>>b[i]>>g[i]>>k[i];
	 }
	 int x,y;
	 cin>>x>>y;
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