//
// Created by ellen on 2022-04-14.
//

#include <iostream>
#include <algorithm>
using namespace std;
const int N = 101;
int n;
int x[N];//最多100个
int bestc;
int cc;//当前权值
int g[N][N];// 邻接矩阵
void backtrace(int t){
    if(t==n){
        if(g[x[n-1]][x[n]] < INT32_MAX && g[x[n]][1] < INT32_MAX
        && (bestc==INT32_MAX || cc+g[x[n-1]][x[n]] + g[x[n]][1] < bestc)  //判断是否存在路径
        ){
            bestc = cc + g[x[n-1]][x[n]] +  g[x[n-1]][1];
        }
    } else{
        //进入 子树 ，连通的邻接点
        //bestc==INT32_MAX || cc + g[x[t-1]][j] < bestc)  剪枝 ，如果小于当前最优值，继续搜索
        for (int j=t; j <= n;++j) {
            if(g[x[t-1]][x[j]]<INT32_MAX && (bestc==INT32_MAX || cc + g[x[t-1]][j] < bestc)){
                //搜索子树
                swap(x[t],x[j]);
                cc+=g[x[t-1]][x[j]];
                backtrace(t+1);
                cc-=g[x[t-1]][x[j]];
                swap(x[t],x[j]);
            }
        }
    }
}

int tsp(){
    for (int i = 1; i <=n; ++i) {
        x[i] = i;
    }
    bestc = INT32_MAX;
    cc = 0;
    //搜索 2-n 的全排列
    backtrace(2);
    return bestc;
}


int main(){

    scanf("%d",&n);



    return 0;
}