#include<vector>
#include<iostream>
using namespace std;
#include<map>
int main(){
    //统计每个人的得票数，并打印出来。 (预期输出：Li: 3, Wang: 2, Zhang: 1)
vector<string> votes = {"Li", "Wang", "Li", "Zhang", "Wang", "Li"};
map<string, int> mp;
for(int i = 0; i < votes.size(); i++) {
        string name = votes[i];
        mp[name]++;
    //如果 mp 里还没有 "Li"，它会自动创建 "Li" 并把值设为 0，然后 ++ 变成 1。
        // 如果 mp 里已经有 "Li" (比如是 2)，直接 ++ 变成 3。
    }
        for(const auto& item : mp) {
        cout << item.first << ": " << item.second << endl;
    }
    
    return 0;
}