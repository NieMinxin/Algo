//
// Created by ellen on 2022-03-16.
//
#include <iostream>
using namespace std;
const int N = 10010;
typedef long long LL;
int a[N],b[N];
bool v[N][N];

int main(){

    int n,pos,h,r;
    scanf("%d%d%d%d",&n,&pos,&h,&r);
    for (int i = 0; i <=n; ++i) {
        a[i] = h;
    }

    while (r--){
        int x,y;
        scanf("%d%d",&x,&y);
        if(x>y) swap(x,y);
        if(v[x][y]){
            continue;//去重
        }
        v[x][y]= true;//
        b[x+1]--;
        b[y]++;//端点不能该
    }

    for (int i = 1; i <=n ; ++i) {
        a[i]=a[i-1]+b[i];
        printf("%d\n",a[i]);
    }

    return 0;
}
