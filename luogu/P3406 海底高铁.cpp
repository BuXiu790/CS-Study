#include<iostream>
#include<math.h>
#include<algorithm>
using namespace std;
const int Q =1e5 +10;
int P[Q];
long long A[Q],B[Q],C[Q];
int arr[Q];
int main(){
	int N;//一共N个城市 
	cin>>N;
	
	int M;//要去M个城市 
	cin>>M;
	
	//输入去的城市的顺序 
	for(int i=1;i<=M;i++){
		cin>>P[i];
	} 
	
	//输入第i段铁路的Ai，Bi，Ci
	for(int i=1;i<=N-1;i++){
		cin>>A[i]>>B[i]>>C[i];
	} 
	
	//计算每段路程走的数量
	 for(int i=1;i<=M-1;i++){
	 	int themax=max(P[i],P[i+1]);
	 	int themin=min(P[i],P[i+1]);
	 	for(int k=themin;k<themax;k++){
	 		arr[k]++;
		 }
	 }
		
	//算出每段路的两种花费
	long long count =0;
	for(int i=1;i<=N-1;i++){
		long long Ap=arr[i]*A[i];
		long long Bp=arr[i]*B[i] + C[i];
		if(arr[i]==0) Bp=0;
		if(Ap>=Bp){
			count += Bp;
		}else{
			count += Ap;
		}
	}		
	cout<<count; 
	
	
	
	
	return 0;
}