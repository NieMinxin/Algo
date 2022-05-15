//
// Created by ellen on 2022-03-27.
//

#include<iostream>
#include<algorithm>
using namespace std;
const int N = 1010;
int v[N],w[N];
int f[N][N];
int main(){
    int n,m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        scanf("%d%d",&v[i],&w[i]);
    }

    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            f[i][j]= f[i-1][j];//不选物品i(n个)
            for(int k=0;k*v[i]<=j;k++){
                f[i][j] = max(f[i][j],f[i][j-k*v[i]]+k*w[i]);
            }
        }
    }

    printf("%d",f[n][m]);
    return 0;
}
