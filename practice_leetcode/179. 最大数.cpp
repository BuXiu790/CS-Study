#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
class Solution {
public:
 static bool cmp(const string a,const string b){
        string s1=a+b;
        string s2=b+a;
       
        return s1>s2;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> v;
       for(auto& x:nums){
        v.push_back(to_string(x));
       }
     
       sort(v.begin(),v.end(),cmp);
       if (v[0] == "0") {
            return "0";
        }
       string s;
       for(auto& x:v){
        string s1=x;
        s=s+s1;

        
       }
    
       return s;
    }
   
    
    
};