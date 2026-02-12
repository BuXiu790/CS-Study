#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
       vector<vector<int>> ret;
       
        int n=nums.size();
        for(int st=0;st<=(1<<n)-1;st++){
            //根据st状态还原出要选的数
            vector<int> tmp;
            for(int i=0;i<n;i++){
                if((st>>i)&1){
                    tmp.push_back(nums[i]);
                }
            }
            ret.push_back(tmp);

        }
        return ret;


    }
};