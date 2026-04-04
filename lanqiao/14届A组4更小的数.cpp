#include <iostream>
using namespace std;
int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 string s;
 cin >> s;
 int cnt = 0;
 int n =s.length();
 for(int center = 0; center < n;++center){
   //奇数中心
   int L = center-1;
   int R = center + 1;
   bool is_valid = false;
   while(L >= 0 && R < n){
    if(s[L] > s[R]){
      is_valid = true;
      cnt++;

    }else if(s[L] < s[R]){
      is_valid = false;
    }
    else{
      if(is_valid){
        cnt++;
      }
    }
    L--;
    R++;
 }
  L =center;
  R = center+ 1;
  is_valid = false;
  while(L >= 0 && R < n){
    if(s[L] > s[R]){
      is_valid = true;
      cnt++;

    }else if(s[L] < s[R]){
      is_valid = false;
    }
    else{
      if(is_valid){
        cnt++;
      }
    }
    L--;
    R++;
 }}
 cout<<cnt;
  return 0;
}