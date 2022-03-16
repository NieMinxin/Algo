//
// Created by ellen on 2022-03-08.
//
#include <iostream>
#include <limits>
using namespace  std;

class Solution {
public:
    int mySqrt(int x) {
        double l = 0, r = x;
        while (r-l>1e-6) {
            double mid = (l+r)/2;
            if (mid * mid* mid<=x) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return (int)l;
    }
};

int main(){
    double x;
    scanf("%lf",&x);

    double l = -1000,r=1000;
    while (r-l>1e-8){
        double mid=(l+r)/2;
        if(mid*mid*mid>=x) r=mid;
        else l=mid;
    }
    printf("%.6lf",l);
    return 0;
}
