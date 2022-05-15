//
// Created by ellen on 2022-03-19.
//

#include <iostream>
using namespace std;
class Solution {
public:
    int lowBit(uint32_t x){
        return x&-x;
    }
    int hammingWeight(uint32_t n) {
        int res =0;
        while (n){
            n-= lowBit(n);
            if(n>0) res++;
        }
        return res;
    }
};
int main(){
    Solution solution;
    return 0;
}