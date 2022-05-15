//
// Created by ellen on 2022-04-02.
//

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 510,INF = 1e9;
int a[N][N];
int f[N][N];
int main(){
    int n;
    cin >> n;
    for (int i = 1; i <=n ; ++i) {
        for (int j = 1; j <=i; ++j) {
            scanf("%d",&a[i][j]);
        }
    }
    for (int i = 1; i <=n; ++i) {
        for (int j = 1; j <=i; ++j) {
            f[i][j] = -INF;
        }
    }
    // 开始递推
    f[1][1] = a[1][1];
    for (int i = 2; i <=n ; ++i) {
        for (int j = 1; j <=i; ++j) {
            if(j==1){
                f[i][j] = f[i-1][j] + a[i][j];
            } else if(j==i){
                f[i][j] = f[i-1][j-1]+a[i][j];
            }else{
                f[i][j] = max(f[i-1][j-1],f[i-1][j]) + a[i][j];
            }
        }
    }
    int res = -INF;
    for (int i = 1; i <=n; ++i) {
        res = max(res,f[n][i]);
    }
    cout << res << endl;
    return 0;
}