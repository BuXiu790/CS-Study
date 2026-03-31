#include <iostream>
using namespace std;
const int N = 1e3 + 10;
int  w[N],v[N];
int dp[N];
int main() {
    int n,V;
    cin >> n >> V;
   for(int i = 1 ; i <= n; i++){
    cin >> v[i] >> w[i];
   }
    for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= V; ++j){
             if(j - v[i] >= 0 ){
 dp[j] =  max(dp[j], dp[j-v[i]] + w[i]);
             }
           
        }
    }
    cout << dp[V]<<endl;
    for(int i = 0 ;i <=V ;i++){
        dp[i] = -1e9+10;
    }
    dp[0] = 0;
        for(int i = 1 ; i <= n ; i++){
        for(int j = 1 ; j <= V; ++j){
            if(j - v[i] >= 0 ){
                dp[j] =  max(dp[j], dp[j-v[i]] + w[i]);
            }
            
        }
    }
    if(dp[V]< 0){
        cout<<0;
    }
    else{
        cout<<dp[V];
    }

}
// 64 位输出请用 printf("%lld")