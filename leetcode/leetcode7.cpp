//
// Creaclass Solution {
//public:
//    int reverse(int x) {
//        int n=x;
//        if(x==0){
//            return 0;
//        }
//        vector<int> C;
//        while(x!=0){
//            C.push_back(x%10);
//            x/=10;
//        }
//        while (C.size()>1 && C.back()==0) C.pop_back();
//
//        int res = 0;
//
//        for (int i = 0; i < C.size(); ++i) {
//            res = res*10+C[i];
//        }
//        if(res>INT32_MAX || res<INT32_MIN){
//            return 0;
//        }
//
//        return  res;
//    }
//};ted by ellen on 2022-03-20.
//
#include <iostream>
using namespace std;
#include <vector>





int main(){

    Solution solution;
   int x =  solution.reverse(123);
    printf("%d",x);
    return 0;
}