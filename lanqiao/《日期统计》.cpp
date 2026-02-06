


#include<iostream>
#include<cmath>
using namespace std;
int  main(){
	static int count=0;
	for(int x =1;x<=2023;x++){
		int k=x/2;
		int sum=x+k;
		
		int root=sqrt(sum);
		if(root*root==sum){
		 count++;
		}
		
	}
	cout<<count<<endl;
} 