#include<iostream>
using namespace std;

const int N=1e6+10;
int a[N],b[N],c[N];
int la,lb,lc;
string x,y;

void mul(int c[],int a[],int b[]){
	//进位相乘，然后相加
	for(int i=0;i<la;i++){
		for(int j=0;j<lb;j++){
			c[i+j]+=a[i]*b[j];
		}
	}
	for(int i=0;i<lc;i++){
		c[i+1] +=c[i]/10;
		c[i] %= 10;
	}
	//去除前导0
	while(lc>1&&c[lc-1]==0)lc--; 
}
int main(){
	cin>>x>>y;
	la=x.size();
	lb=y.size();
	lc=la+lb;
	//逆序排列 
	for(int i=0;i<la;i++){
		a[i]=x[la-1-i]-'0';
	}
	for(int i=0;i<lb;i++){
		b[i]=y[lb-1-i]-'0';
	}
	//先不进位相乘，然后相加，最后处理进位0 
	mul(c,a,b);//c= a*b
	for(int i=lc-1;i>=0;i--){
		cout<<c[i];
	}
	return 0;
} 