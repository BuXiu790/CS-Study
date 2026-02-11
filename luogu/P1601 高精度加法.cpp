#include<iostream>
using namespace std;
const int N=1e6+10;
int a[N],b[N],c[N];
int la,lb,lc;


void add(int c[],int a[],int b[]){
	for(int i=0;i<lc;i++){
		c[i] += a[i]+b[i];//对应位相加 
		c[i+1] +=c[i]/10;//处理进位 
		c[i] %= 10;//处理当前位，当前位是取余数 
		
	}
	if(c[lc])lc++;//边界情况，如果c进位， 长度要加1 
}


int main(){
	string x,y;
	cin>>x>>y;
	//用字符串存储大数 
	la=x.size();
	lb=y.size();
	lc=max(la,lb);
	//把每一位数逆序放在数组中 
	for(int i=0;i<la;i++){
		a[la-1-i]=x[i]-'0';
	}
	for(int i=0;i<lb;i++){
		b[lb-1-i]=y[i]-'0';
	}
	//模拟算法
	 add(c,a,b);//c=a+b
	 for(int i=lc-1;i>=0;i--){
	 	cout<<c[i];
	 } 
	return 0;
}