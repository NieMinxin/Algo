//
// Created by ellen on 2022-04-09.
//

#include <iostream>
using namespace std;
const int N = 100010 , P = 131;//131进制
char s[N];
int h[N],p[N];

typedef  unsigned long  long ULL;//2^64 溢出直接代表取模
ULL query(int l,int r){
    return (h[r] - h[l-1]) * p[r-l+1];
}
int main(){

    int n,m;
    cin >> n >> m;
    scanf("%s",s);
    p[0] = 1; // p^0 = 1;
    for (int i = 1; i <=n; ++i) {
        p[i] = p[i-1]*P;// 前缀 和
        h[i] = h[i-1] * P +s[i];
    }

    while (m--){
        int l1,r1,l2,r2;
        scanf("%d%d%d%d",&l1,&r1,&l2,&r2);
        if(query(l1,r1)== query(l2,r2)) printf("Yes\n");
        else printf("No\n");
    }


    return 0;
}