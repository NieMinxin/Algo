//
// Created by ellen on 2022-04-03.
//
#include <iostream>
using namespace std;
const int N = 310;
int m[N];
int s[N];
int dp[N][N];

int main(){
    int n;
    cin >> n;
    for (int i = 1; i <=n; ++i) {
        scanf("%d",&m[i]);
    }
    // 前缀和
    for (int i = 1; i <=n; ++i) {
        s[i] = s[i-1] + m[i];
    }

    //从区间的长度开始枚举
    for (int l = 2; l <=n; ++l) {
        // n-1
        int i;
        int j;
        for (i = 1; i+l -1 <= n; ++i) {
            // 每一行 多少个元素，前面的不用乘
            j = i+l-1;// 区间的右端点
            dp[i][j] = dp[i+1][j]  + s[j] - s[i-1];
        }
        // 开始切分
        for (int k = i+1; k<j;++k) {
            dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+s[j] -s[i-1]);
        }
    }
    cout << dp[1][n] << endl;
    return 0;
}