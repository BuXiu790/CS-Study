#include <iostream>
#include<map>
#include<set>
//遍历数字用到map
//查重用到set
//暴力导致超时
using namespace std;
long long MOD = 1000000007;
const int N =5e5 + 10;
int a[N];

  int ans = 0;//总数
   map<int,int> mp;
void dfs(int step,int K){
  //截止条件
  if(step == K -2 ){
    ans ++;
    ans = ans % MOD;
    return;
  }
  //遍历每个数字
  for(auto it = mp.begin(); it != mp.end(); ++it){
    if(it->second <= 0)continue;
    it->second--;
    dfs(step+1,K);
    it->second++;
  }
  

}
int main()
{
  int K;
  cin >> K;
 
  for(int i = 1; i <= K; i++){
    cin >> a[i];
    mp[a[i]]++;
    //记录每个数字有几次
  }
set<pair<int,int>> st;
  for(int i = 1; i <= K; i++){
    for(int j = 1; j <= K; j++){
      if(i == j) continue;
      long long sum = a[i] * a[j];
      if(sum == K -2){
        //把行和列的数量减去
        //这种排列 
        if(st.count({a[i],a[j]}) == 0){
		
        st.insert({a[i],a[j]});
        mp[a[i]]--;
        mp[a[j]]--;
        dfs(0,K);
        mp[a[i]]++;
        mp[a[j]]++;
    }
      }
    }
  }
  cout<<ans;
  return 0;
}