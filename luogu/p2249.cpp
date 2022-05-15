//
// Created by ellen on 2022-03-19.
//

#include <iostream>
using namespace std;
const int N = 1000000;
int a[N];

int bin_s(int l,int r,int x){
    while(l<=r){
        int mid = r+l >>1;
        if(a[mid]>=x) r = mid;
        else l = mid+1;
    }
    if (a[l]==x) return l; //找都了就输出他的位置
    else return -1; // 没找到输出-1
}

int main(){

    int n,m;
    cin >> n >>m;
    for (int i = 1; i <=n; ++i) {
        scanf("%d",&a[i]);
    }
    while (m--){
        int x;
        scanf("%d",&x);

        int l = 1,r=n;
        printf("%d ", bin_s(l,r,x));

    }

    return 0;
}