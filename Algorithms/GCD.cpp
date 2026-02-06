//求最大公约数
#include<iostream>
using namespace std;


int gcd1(int a, int b){
    int max,min;
    if(a>=b){
        max=a;
        min=b;
    }
    else{
         max=b;
         min=a;
    }
    while(min!=0){
        int t =min;
        min =max%min;
        max=t;
    }
    return max;

}
int gcd2(int a, int b){
    while(b!=0){
        int t=b;
        b = a % b;
        a = t;
    }
    return a;
}



int gcd3(int a,int b){
    if(b==0) return a;
    return gcd3(b,a%b);

}
int lcm(int a, int b){
    return (a*b)/gcd1(a,b);

}