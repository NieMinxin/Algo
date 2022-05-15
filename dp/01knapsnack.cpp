//
// Created by ellen on 2022-03-23.
//
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1010;
int v[N],w[N];
int f[N];
int main(){
    int n,m;//m 代表重量

    cin >> n >> m;

    for (int i = 1; i <=n; ++i) {
        scanf("%d%d",&v[i],&w[i]);
    }


    for (int i = 1; i <=n ;++i) {
        for (int j = m;j>=v[i] ; --j) {
            f[j] = max(f[j],f[j-v[i]]+w[i]);
        }
    }
    printf("%d",f[m]);

    return 0;
}
