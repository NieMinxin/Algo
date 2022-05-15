//
// Created by ellen on 2022-03-27.
//
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100;
int p[N];
int dp[N],s[N];

//朴素递归算法
int cut(int p[],int n) {
    //如果长度为0，则0收益
    if (n == 0)
        return 0;
    int q = -1;
    // <n确保了钢条 切割范围
    for (int i = 0; i <n; i++) {
        q = max(q, p[i] + cut(p, n - i - 1));    //切割后的收益和不切割
    }
    return q;

}

//重构解
int cut_rod(int p[],int n){
    dp[0] = 0;// 钢条长度为 0
    for (int i = 1; i <=n; i++) {
        int res = -1;
        for (int j = 1; j <=i ; j++) {
            res = max(res,p[j-1]+dp[i-j]);
        }
        dp[i]=res;
    }
    return dp[n];
}

int main(){

    int len,n;
    cin >> len;
    cin >> n;
    for (int i = 0; i <n; ++i) scanf("%d",&p[i]);
    int rs = cut_rod(p,len);
    cout << rs << endl;
    return 0;
}