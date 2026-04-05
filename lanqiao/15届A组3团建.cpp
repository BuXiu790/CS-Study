#include <iostream>
#include<vector>
using namespace std;
const int N = 2e5 + 10;
int c[N],d[N];
  vector<int> v1[N];
  vector<int> v2[N];
  int n , m;
  int ans;
  void dfs(int u1 ,int u2,int f1 ,int f2 ,int depth){
    //f1,f2用来记录上次的路，防止走回头路
    ans = max(ans,depth);
    //两次for循环对比
    for(auto x1 : v1[u1]){
      if(x1 == f1)continue;
      for(auto x2 : v2[u2]){
        if(x2 == f2) continue;
        if(c[x1] == d[x2]){
          
          dfs(x1,x2,u1,u2,depth+1);          
        }
      }
    }

  }
int main()
{


  cin >> n >> m;
  for(int i = 1 ; i <= n; ++i){
    cin >>c[i];
  }
    for(int i = 1 ; i <= m; ++i){
    cin >>d[i];
  }
  int u , v;
  //建立邻接表
  for(int i = 1 ; i <= n-1; ++i){
    cin >> u >> v;
    v1[u].push_back(v);
    v1[v].push_back(u);
  }
  for(int i = 1 ; i <= m-1; ++i){
    cin >> u >> v;
    v2[u].push_back(v);
    v2[v].push_back(u);
  }
  int depth = 0;
if(c[1] == d[2]){
 dfs(1,1,0,0,1);
  cout<<ans;
}else{
  cout<<0;
}
 
  return 0;
}