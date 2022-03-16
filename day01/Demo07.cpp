//
// Created by ellen on 2022-03-08.
//
#include <iostream>
#include <vector>
using namespace  std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res={0,0};
        int l =0,r=nums.size()-1;
        while (l<r){
            int mid = l+r>>1;
            if(nums[mid]>=target) r = mid;
            else l = mid+1;
        }
        if(nums[l]!=target){
            res[0]= -1;
            res[1] = -1;
        } else{
            res[0] = l;
            int l = 0,r=nums.size()-1;
            while (l<r){
                int mid = l+r+1>>1;
                if(nums[mid]<=target) l=mid;
                else r = mid-1;
            }
            res[1] = l;
        }
        return res;
    }
};

int main(){
    Solution solution ;
    int arr[6]{5,7,7,8,8,10};
    vector<int> nums(arr,arr+6);
    vector<int> t = solution.searchRange(nums,8);
    cout << t[0] << endl;
    cout << t[1] << endl;
    return 0;
}

