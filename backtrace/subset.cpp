//
// Created by ellen on 2022-04-13.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;
    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0,nums);
        return ans;
    }

    void dfs(int cur,vector<int> &nums){
        if(cur == nums.size()){ ans.push_back(t); // C++ 添加一个集合}
        //选取
        t.push_back(nums[cur]);
        dfs(cur+1,nums);
        t.pop_back();//回溯

        //不取
        dfs(cur+1,nums);
    }

};


int main(){


    return 0;
}