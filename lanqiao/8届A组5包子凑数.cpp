#include <iostream>
#include<set>
#include<algorithm>
#include<numeric>
const int MAX =1e4 + 10;
using namespace std;
const int N = 110;
int a[N];
bool f[MAX];
int main()
{
  set<int> s;
  int n;
  cin >> n;
  int g = 0;
  for(int i = 1 ; i <= n; i++){
    cin >> a[i];
    g=gcd(g,a[i]);
    
  }
  if(g > 1){
    cout<<"INF";
    return 0;
  }
  sort(a,a+n+1);
  f[0] = true;
  for(int i = 1; i <= MAX; i++){
    for(int j = 1; j <= n ;j++){
      if(i >= a[j]&&f[i-a[j]] == true){
        f[i] = true;
      }
    }
  }
  int count = 0;
  for(int i = 1; i <= MAX ; i++){
    if(f[i] == false){
      count++;
    }
  }
  cout<<count;
  return 0;
}