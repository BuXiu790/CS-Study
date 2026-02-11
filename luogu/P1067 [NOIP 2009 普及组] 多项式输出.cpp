#include<iostream>
using namespace std;
int main(){
	int N;//最高次 
	cin>>N;
	int a[999];//每一项系数
	for(int i=N;i>=0;i--){
		cin>>a[i];
	}
	//输入处理完毕

	for(int i=N;i>=0;i--){
	//分成符号，系数，次数三部分输出
	
	if(a[i]==0)continue;
	
	 //符号
	 if(a[i]<0)cout<<"-";
	 else{
	 	if(i!=N)cout<<"+";
	 } 
	 
	 //数字,先取绝对值
	 a[i]=abs(a[i]);
	 if(a[i]!=1||(a[i]==1&&i==0)){
	 	cout<<a[i];
	 }
	 
	 //次数
	 if(i==0) continue;
	 else if(i ==1){
	 	cout<<"x";
	 }
	 else{
	 	cout<<"x^"<<i;
	 }
	  
	 
	
	} return 0;}
	
