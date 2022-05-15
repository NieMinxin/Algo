//
// Created by ellen on 2022-03-16.
//

#include <iostream>
using namespace std;
const int N = 100010;
int a[N],b[N];

void insert(int l,int r,int v){
    b[l]+=v;
    b[r+1]-=v;
}


int main ()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 1; i <=n; ++i) {
        scanf("%d",&a[i]);
    }
    //初始化差分数组
    for (int i = 1; i <=n; ++i) insert(i,i,a[i]);
    // b1 = a1 ,b2 = -a1,下一次循环 b2 = a2-a1 ....类推  bn+1 = -bn (不影响结果)
    while (m--){
        int l,r,v;//v为添加的值
        scanf("%d%d%d",&l,&r,&v);
        insert(l,r,v);
    }
    //最后求原数组 在区间加上数后 ---的数列
    for (int i = 1; i <=n ; ++i) {
        b[i]+=b[i-1]; //b0 =0
    }

    for (int i = 1; i <=n ; ++i) {
        printf("%d ",b[i]);
    }

    return 0;
}


