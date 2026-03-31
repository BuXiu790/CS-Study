#include<iostream>
using namespace std;
const int N = 2010;
int new_v[N];
int new_w[N];
int x[N],w[N],v[N],dp[N];
int cnt;
int main(){
    int n,T;
    cin >> n>>T;
    for(int i = 1; i<= n; i++){
        cin >> x[i] >> v[i] >> w[i];
        
        int k =1;
        while(x[i] >= k){
            //二进制拆分
            //o（logN）
            cnt++;
            new_w[cnt] = k*w[i];
            new_v[cnt] = k*v[i];
             x[i]-=k;
            k = k* 2;
           //把多重背包换成cnt个01背包

        }
        if(x[i] > 0){
            cnt++;
            new_w[cnt] = x[i] * w[i];
             new_v[cnt] = x[i]*v[i];
}
    }
    //01背包解法，总数是cnt
    for(int i = 1; i<= cnt ; i++){

    for(int j = T; j >= new_v[i];--j){
        dp[j] = max(dp[j],dp[j-new_v[i]] + new_w[i]);
    }}
    cout<<dp[T];
    
    return 0;
}