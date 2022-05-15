//
// Created by ellen on 2022-04-20.
//
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100;
int g[N];
int res[N];
int main(){

    int n,k;
    cin >> n >> k;
    //加油站的间距 ,a[k+1]表示第k个加油站与第k-1 个加油站之间的距离
    //有k+1个整数，表示第k个加油站与第k-1个加油站之间的距离。
    for (int i=0;i<=k; ++i) {
        scanf("%d",&g[i]);
        if(g[i]>k){
            printf("No Solution\n");
            return 0;
        }
    }
    int count = 0;
    int s = k;
    //枚举
    for (int i = 0; i<=k; ++i) {
        if(s>=g[i]){
            s-=g[i];
        }else{
            s = k;
            count++;
            res[i]=i;
            s -=g[i];
        }
    }
    printf("加油点 :");
    for (int i = 0; i <=k; ++i) {

        if(res[i]!=0){
            printf("%d ",res[i]);
        }
    }
    cout << endl;
    cout << "加油总次数" << count << endl;
    return 0;
}