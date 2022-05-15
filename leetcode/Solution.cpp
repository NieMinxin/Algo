//
// Created by ellen on 2022-04-02.
//
#include <vector>
#include <iostream>
#include <algorithm>
using namespace  std;
class Solution {

public:
    int lengthOfLIS(vector<int>& nums) {
        int dp[nums.size()];
        for(int i=0;i<nums.size();i++){
            dp[i] = 1; // 只有一个数
            for (int j = 0; j < i;j++) {
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
        }
        int res  = 0;
        for (int i = 0; i < nums.size(); ++i) {
            res = max(res,dp[i]);
        }
        return res;
    }
};