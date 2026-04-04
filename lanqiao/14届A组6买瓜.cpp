#include <iostream>
#include<algorithm>
typedef long long ll;
using namespace std;
const int N = 50;
long long A[N];
ll B[N];
ll n , m;
ll suf[N];//后缀和数组
int ans;
int ret = 1e8+10;
bool cmp(ll a,ll b){
return a > b;
}
void dfs(ll a,ll u){
 
  if(a>m)return;
  if(ans >= ret) return ;//最优化剪枝
   //截止条件
  //拿到的已经等于m
  if(a==m){
    ret = min(ans,ret);
    return;}
//u表示在选第几个瓜
  for(int i = u; i <n ;i++){
    //第u个瓜，有三种选法，选全部，选一半，不选
    //如果加上后续的都无法达到m，直接剪枝
    if(a + suf[i] < m) return ;
    a+=A[i];
    dfs(a,i+1);
    a-=A[i];
    a+=B[i];
    ans++;
    dfs(a,i+1);
    a-=B[i];
    ans--;

  }



}



int main()
{
  
  cin >> n >> m;
  //
  for(int i =0 ; i < n;++i){
    cin >> A[i];
    B[i] = A[i];
    A[i] *= 2;
    //把m和A[i]都乘2,防止/精度问题
  }
  m = m* 2;

  //排序从大的往小的选
sort(A,A+n,cmp);
sort(B,B+n,cmp);
//后缀和数组
suf[n-1] = A[n-1];
for(int i = n-2; i>=0;i--){
  suf[i] =suf[i+1] + A[i];
}
dfs(0,0);
if(ret==1e8+10){
  cout<<-1;
}
else{
  cout<<ret;
}
  return 0;
}