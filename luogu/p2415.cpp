//
// Created by ellen on 2022-03-31.
//
#include <iostream>
#include <cmath>
using namespace std;
const int N =35;
int a[N];

int main(){


    long long s=0;
    int i=0;
        //cout<<s;
        while(cin>>a[i++]);//合写cin>>a[i];i++;
        for(int j=0;j<i;j++){
            s+=a[j];
        }
        s*=pow(2,i-2);//注意，i-2!
        cout<<s;
        return 0;

}
