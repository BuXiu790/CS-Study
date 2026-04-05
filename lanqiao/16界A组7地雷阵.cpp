#include <iostream>
#include<cmath>
#include<algorithm>
#include<vector>
using namespace std;
const int N =1e5 + 10;
double x[N],y[N],r[N],d[N];
int main()
{
  //得出PI
  double PI = acos(-1.0);

//存储每个圆的左边界和右边界
  vector<pair<double,double>> v;
  int n;
  cin >> n;
  for(int i = 1; i <= n; ++i){
    cin >> x[i] >> y[i] >> r[i];
    
     d[i] = hypot(x[i],y[i]);
     if(d[i] <= r[i]){
       cout<< 0.000;
       return 0;
      }
      //圆心与x轴夹角
     double alpha = atan2(y[i],x[i]);
     //切线与x轴夹角
     double delta = asin(r[i] / d[i]);
     double L = alpha - delta;
     double R = alpha + delta;
     double L_bound = max(0.0,L);
     double R_bound = min(PI/2.0,R);
     //算出左边界和右边界
     if(L_bound < R_bound){
    v.push_back({L_bound,R_bound});
     }
  }
  //sort自动排序v[i].first
sort(v.begin(),v.end());
//记录阴影部分
  double cover = 0.0;
  double f = 0.0;
  double curr_l = v[0].first;
  double curr_r = v[0].second;
  if(!v.empty()){
  for(int i = 1 ; i < v.size() ; ++i){
    //保证v[i]区间在curr_l 到 curr_r的内部，在外部就开新区间
    if(v[i].first <= curr_r){
      curr_l = min(curr_l,v[i].first);
      curr_r = max(curr_r,v[i].second);

    }else{
        //开一个新的区间，记录旧区间
    cover += curr_r - curr_l;
    curr_l = v[i].first;
    curr_r = v[i].second;
    }
  }
  cover += curr_r -curr_l;}
  f = cover /(PI / 2.0);
  f= 1.0 -f;

  printf("%.3f",f);
  return 0;
}