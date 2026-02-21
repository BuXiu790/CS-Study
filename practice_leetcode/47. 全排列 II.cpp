#include<iostream>
#include<vector>
#include<map>
using namespace std;
//给定一个可包含重复数字的序列 nums 
//按任意顺序 返回所有不重复的全排列
class Solution {
	    map<int,int> mp;
        map<int,int> book;
        vector<int> v;
        vector<vector<int>> v2;
        vector<int> unique_nums;
        int n;
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
		n = nums.size();
		for(int i = 0; i < n; i++)
       {
       	if(mp[nums[i]]==0){
       		unique_nums.push_back(nums[i]);
		   }
		   mp[nums[i]]++;
	   }
      AA(0);
      return v2;
   
}

void AA(int k){
	if(k >= n){
		v2.push_back(v);
		return;
	}
	
	for(int i = 0; i < unique_nums.size(); i++){
		int current_num = unique_nums[i] ;
		
	
	if(book[current_num] >= mp[current_num]){
		continue;
	}
	
	v.push_back(current_num);
	book[current_num]++;
	
	AA(k+1);
	book[current_num]--;
	v.pop_back();
	
	
}
	
}
	
} ;


