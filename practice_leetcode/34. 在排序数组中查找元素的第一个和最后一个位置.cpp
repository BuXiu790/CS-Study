#include<iostream>
using namespace std;
#include<vector>
 vector<int> searchRange(vector<int>& nums, int target) {
        
        int n=nums.size();
        int left=0,right =n-1;
        int mid =0;
        if(n==0) return {-1,-1};
        //寻找左边界 
     
		 while(left<right){
        	mid=left+(right-left)/2; 
        	if(nums[mid]>=target)right = mid ;
        	else left = mid + 1;
	}
	if(nums[left]!=target)return {-1,-1};
		int a1 =left;
	left=0;
	right =n-1;
	mid =0;
	 	while(left<right){
	 		mid=left+(right-left+1)/2; 
	 		if(nums[mid]<=target) left =mid;
	 		else right = mid -1;
			 }
		 
		 int a2;
		 a2=left;
		 
	return {a1,a2};}
	
	
	
 