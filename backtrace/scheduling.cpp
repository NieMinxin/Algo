//
// Created by ellen on 2022-04-14.
//

#include <iostream>
#include <algorithm>
using namespace std;
int n ;//n个作业

const int N = 100;
int m[N][N];////m[j][i]表示在第i台机器上作业j的处理时间
int f1;// 机器1 完成时间
int f2[N] ;//机器2 完成时间
int f,x[N],bestx[N];
int bestf = INT32_MAX;

void backtrace(int t){
    if(t>n){
        for (int i = 1; i <=n; ++i) {
            bestx[i] = x[i];
        }
        bestf = f;

    }else
    {
        for (int i = t; i <=n; ++i) {
            f1 = m[x[i]][1];
            f2[i] = (f2[i-1]<f1 ? f1 : f2[i-1]) + m[x[i]][2];
            f+=f2[i];
            //剪枝
            if (f<bestf){
                swap(x[i],x[t]);
                backtrace(t+1);
                swap(x[i],x[t]);
            }
            f1-=m[x[i]][1];
            f-=f2[i];
        }
    }

}

int main(){

    scanf("%d",&n);
    for (int i = 1; i <=2; ++i) {
        for (int j = 1; j <=n; ++j) {
            scanf("%d",&m[j][i]);
        }
    }
    for (int i = 1; i <=n; ++i) {
        x[i] = i;
        bestf = INT32_MAX;
    }

    backtrace(1);
    cout << bestf << endl;
    return 0;
}