//高精度除以低精度
#include<iostream>
using namespace std;

const int N=1e6+10;
int a[N],b,c[N];
int la,lc;
string x,y;

void sub(int c[],int a[],int b){
	long long t=0;
	for(int i=la-1;i>=0;i--){
		t=t*10 +a[i];
		c[i]=t/b;
		t%=b;
	}
	while(lc>1&&c[lc-1]==0)lc--;
}

int main(){
	cin>>x>>b;
	la=x.size();

	lc=la;
	//逆序排列 
	for(int i=0;i<la;i++){
		a[i]=x[la-1-i]-'0';
	}


	sub(c,a,b);//c= a/b
	for(int i=lc-1;i>=0;i--){
		cout<<c[i];
	}
	return 0;
} 