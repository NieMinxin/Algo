//
// Created by ellen on 2022-05-15.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        int q[nums.size()+1];
       int   hh = 0, tt = -1;
        for (int i = 0; i < nums.size(); i ++ )
        {
            if (hh <= tt && i - k + 1 > q[hh]) hh ++ ;

            while (hh <= tt && nums[q[tt]] <= nums[i]) tt -- ;
            q[ ++ tt] = i;

            if (i >= k - 1) res.push_back(nums[q[hh]]);
        }
        return  res;
    }
};

int main(){


    return 0;
}