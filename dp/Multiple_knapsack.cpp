//
// Created by ellen on 2022-03-31.
//
#include <iostream>
using namespace std;
const int N = 2010;
int v[N],w[N],s[N];
int f[N];
int main(){
    int n,m;
    cin>>n >> m;
   /* for (int i = 1; i <=n; ++i) {
        scanf("%d%d%d",&v[i],&w[i],&s[i]);
    }*/
    /*//开始递推
    for (int i = 1; i <=n; i++) {
        for (int j = 0; j <=m; j++) {
            //枚举个数
            for (int k = 0; k <=s[i] && k*v[i]<=j; k++) {
                f[i][j] = max(f[i-1][j],f[i][j-k*v[i]]+k*w[i]);// 枚举
            }

        }
    }*/

    // 二进制优化成 0-1 背包
    int cnt = 0;
    for (int i = 1; i <=n; i++) {
        int a,b,s;
        cin >> a >> b >> s;
        int k = 1;
        while (k<=s){
            cnt++;
            v[cnt] = a*k; //系数
            w[cnt] = b*k;
            s-=k;
            k*=2;
        }
        if(s>0){
            cnt++;
            v[cnt] = a*s;
            w[cnt] = b*s;
        }
    }

    n = cnt;
    // 0-1背包
    for (int i = 1; i <=n; i++) {
        for (int j = m; j>=v[i];j--) {
            f[j] = max(f[j],f[j-v[i]]+w[i]);
        }
    }

    cout << f[m] << endl;
    return 0;
}