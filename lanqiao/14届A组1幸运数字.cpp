#include <iostream>
using namespace std;

bool check(int i){
  int a[10];
  int len = 0;
  int sum1 = 0;
  int sum2 = 0;
  while(i > 0){
    a[len] = i % 10;
    len ++ ;
    i = i / 10;
  }
  if(len % 2 != 0) return false;
  int half = len / 2;
  for(int j = 0 ; j < half; j++){
    sum1 += a[j];
    sum2 += a[j+half];
  }
if(sum1 == sum2) return true;
return false;
}
int main()
{
    int count = 0;
  for(int i = 1; i <= 100000000; i++){
    if(check(i)){
      count ++;
    }
  }
  cout << count; 
  return 0;
}