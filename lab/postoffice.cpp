//
// Created by ellen on 2022-04-28.
//
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1000;
int a[N],b[N];

bool cmp(int a,int b) {
    return a < b;
}
int main(){
    int n;//居民点的个数

    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d",&a[i],&b[i]);//居民点 x,y
    }

    sort(a,a+n, &cmp);

    sort(b,b+n, &cmp);

    int x=a[n/2];
    int y=b[n/2];
    long long res = 0;
    for (int i = 0; i <n; ++i) {
        res += abs((a[i]-x)+(b[i]-y));
    }
    printf("%lld",res);
    return 0;
}