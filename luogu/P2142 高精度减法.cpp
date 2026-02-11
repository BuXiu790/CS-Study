#include<iostream>
#include<string>
using namespace std;
	const int N=1e6 +10;

	int a[N],b[N],c[N];
		int la,lb,lc;
bool cmp(string& x,string& y){
	if(x.size()!=y.size())return x.size()<y.size();
	//x长度小于y，return true，交换位置 
	return x<y;
	//x 
	
}

void sub(int c[],int a[],int b[]){
	for(int i=0;i<lc;i++){
		c[i] += a[i]-b[i];//对应位相减 
		if(c[i]<0){
			c[i+1] -=1;
			c[i] +=10;
		}
	}
	//处理前导0
	while(c[lc-1]==0&&lc>1) lc--;
}
int main(){

	string x,y;
	cin>>x>>y;
	
	//比较x，y大小
	//x<y就交换位置 
	if(cmp(x,y)){
		swap(x,y);
		cout<<"-";
	} 
	
	la=x.size();
	lb=y.size();
	lc=max(la,lb);
	for(int i=0;i<=la-1;i++){
		a[i]=x[la-1-i]-'0';
	}
	for(int i=0;i<=lb-1;i++){
		b[i]=y[lb-1-i]-'0';
	}
	sub(c,a,b);//c=a-b
	for(int i=lc-1;i>=0;i--){
		cout<<c[i];
	}
	
	
	
} 