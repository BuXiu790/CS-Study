#include<iostream>
using namespace std;
//右，下，左，上，四个方向 
int dr[]={0,1,0,-1};
int dc[]={1,0,-1,0};
const int N=15;
int arr[N][N];
int book[N][N];
int main(){
	int n;
	cin>>n;
	 int r=1,c=1;//初始位置
	 int cur=1;//当前位置填的数
	 int pos=0;//初始方向 
	 while(cur<=n*n){
	 	arr[r][c]=cur;
	 	cur++;
	 	book[r][c]=1;
	 	int a=r+dr[pos];
	 	int b=c+dc[pos];
	 	if(a<1||b<1||a>n||b>n||book[a][b]==1){
	 		pos=(pos+1)%4;
		 }
		 r=r+dr[pos];
		 c=c+dc[pos];
		 
	 } //矩阵填写完成，输出矩阵
	 for(int i=1;i<=n;i++){
	 	for(int j=1;j<=n;j++){
	 		printf("%3d",arr[i][j]);
		 }
		 cout<<endl;
	 }
	 
	return 0;
}