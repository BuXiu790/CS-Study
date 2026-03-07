#include <iostream>
using namespace std;
const int N =100;
long long a[N];
long long b[N];

long long seek(long long ceng, long long b){
  //截至条件
  if(ceng == 2){
    if(b==1) return 1;
    if(b == 2) return 0;
  }

    //x为父节点在上一层的位置
    long long x = (b+1)/2;
    //求出当前的父节点
    long long curr = seek(ceng -1 ,x);

    //父节点为1
    if(curr == 1){
        if(b % 2 == 1) return 1;
        if(b % 2 == 0) return 0;
    }
    if(curr == 0){
        if(b % 2 == 1) return 0;
        if(b % 2 == 0) return 1;
    }

}

int main()
{
  int m;
  cin >> m;
  for(int i = 1; i <= m; i++){
    cin >> a[i]>>b[i]; 
  }
  for(int i = 1; i <= m; i++){
    if(a[i] == 1){
         cout<<"RED"<<endl;
         continue;
    }
    if(seek(a[i],b[i]) == 1) {
      cout<<"RED"<<endl;
    }
    else{
      cout<<"BLACK"<<endl;
    }
  }





  return 0;
}