//
// Created by ellen on 2022-03-19.
//

#include <iostream>
using namespace std;

int main(){

    long long  a,b,p;
    cin >> a >> b >> p;
    long long  res =1,base =a;
    long long n = b;
   while(b>0){
       if(b&1){
           res *=base;
           res % p;
       }
       base*=base;
       base % p;
       b >> 1;//右移一位
   }

    printf("%lld^%lld mod %lld=%lld",a,n,p,res);
    return 0;
}

