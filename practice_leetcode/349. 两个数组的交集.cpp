#include<vector>
#include<iostream>
#include<set>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s1;
        for(int i=0;i<nums1.size();i++){
            s1.insert(nums1[i]);
        }
        vector<int> result;
        set<int> result2;
        for(int i=0;i<nums2.size();i++){
            if(s1.count(nums2[i])){
                result2.insert(nums2[i]);
            }
        }
        for(auto x :result2){
            result.push_back(x);
        }
        //vector<int> result(result2.begin(), result2.end());
       return result;
    }
};