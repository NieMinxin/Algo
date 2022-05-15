//
// Created by ellen on 2022-05-08.
//
#include <iostream>
using namespace std;
const int  N = 1000010;
int a[N];
int main(){
    double s[N];
    int t;
    cin >>t;

    int m = t;
    while(m--){
        int n;
        cin >>n;
        double  res = 0.0;
        for (int i = 1; i <=n; ++i) {
            if(i&1!=0){
                res +=1/i;
            }else{
                res-=1/t;
            }
        }
        printf("%.5lf",res);
    }


    return 0;
}