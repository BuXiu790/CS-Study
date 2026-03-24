#include <iostream>
#include<string>
using namespace std;
typedef long long ll;
const int N = 1000;
int a[N];
int a2[N];
int b[N];
int b2[N];
int c[N];
int main()
{
 string x,y;
 cin >> x;
 cin >> y;
 if (x[0] == '-') x = x.substr(1);
    if (y[0] == '-') y = y.substr(1);
ll lx = x.length();
ll ly = y.length();

//倒叙存放
 for(int i = 0 ; i < lx ; i++){
  a[i] = x[lx-i-1] - '0';
 }
  for(int i = 0 ; i < ly ; i++){
  b[i] = y[ly-i-1] - '0';
 }
for(int i = 0 ; i < lx ; i++){
  //A2
 for(int j = 0; j <lx ; j++){
   a2[i+j] += a[j] * a[i];
 }
}
ll la2 = lx + lx;
for(int i = 0 ; i <= la2; i++){
  a2[i+1] += a2[i] / 10;
  a2[i] = a2[i] % 10;
}
while(la2 > 1 && a2[la2-1]==0)la2--;


for(int i = 0 ; i < ly ; i++){
  //A2
 for(int j = 0; j <ly ; j++){
   b2[i+j] += b[j] * b[i];
 }
}
ll lb2 = ly + ly;
for(int i = 0 ; i <= lb2; i++){
  b2[i+1] += b2[i] / 10;
  b2[i] = b2[i] % 10;
}
while(lb2 > 1 && b2[lb2-1]==0)lb2--;
ll lc = max(la2,lb2);
bool swap1 = false;

if (la2 < lb2) {
        swap1 = true;
    } else if (la2 == lb2) {
        // 长度相等时，从高位到低位逐位比较
        for (int i = la2 - 1; i >= 0; i--) {
            if (a2[i] < b2[i]) {
                swap1 = true;
                break;
            } else if (a2[i] > b2[i]) {
                break; // 如果 a2 > b2，不用交换，直接结束比较
            }
        }
    }
if(swap1==false){
for(int i = 0; i < lc;i++){
  c[i] += a2[i] -b2[i];
  if(c[i]<0){
    c[i] +=10;
    c[i+1]--;
  }
}
while(lc > 1 && c[lc-1]==0)lc--;
for(int i = lc-1 ; i >= 0 ;i--){
  cout<<c[i];
}
}else{

  for(int i = 0; i < lc;i++){
  c[i] += b2[i] -a2[i];
  if(c[i]<0){
    c[i] +=10;
    c[i+1]--;
  }
}
while(lc > 1 && c[lc-1]==0)lc--;
cout<<"-";
for(int i = lc-1 ; i >= 0 ;i--){
  cout<<c[i];
}
}



  return 0;
}