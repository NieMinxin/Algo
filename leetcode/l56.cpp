//
// Created by ellen on 2022-03-22.
//
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if(intervals.size()==0){
            return res;
        }
        int len = intervals.size();
        sort(intervals.begin(),intervals.end());//排序
        int start = INT32_MIN,end = INT32_MIN;
        for (int i = 0; i < len ; ++i) {
            if(end < intervals[i][0]){
                if(start!=INT32_MIN) res.push_back(vector<int>{start,end});
                start = intervals[i][0],end = intervals[i][1];
            } else{
                end = max(end,intervals[i][1]);
            }
        }
        //处理最后一个
        if(start!=INT32_MIN) res.push_back(vector<int>{start,end});
        return res;
    }
};
int main(){


    return 0;
}

