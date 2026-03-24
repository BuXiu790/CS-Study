#include <iostream>
using namespace std;
int ans;
int score;
void dfs(int step){
  if(score == 70) ans ++;
  if(score == 100) return ;
   if(step ==30) return ;



for(int i = 1; i <= 2; i++){
  if(i == 1){
    score += 10;
    dfs(step+1);
    score -= 10;
    //回溯
  }
  if(i == 2){
    int temp = score;
    score = 0;
    dfs(step+1);
    score = temp;
  }
}
}
int main()
{
  
  dfs(0);
  cout << ans;
  return 0;
}