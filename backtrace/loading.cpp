//
// Created by ellen on 2022-04-13.
//
#include <iostream>
#include <vector>
using namespace std;


class  Loading{
    int n;//集装箱数量
    vector<int> w;// 集装箱重量数组
    int c;// 第一艘轮船载重
    int cw;//当前载重
    int bestw;//最优载重

    int r;//剪枝 剩余集装箱重量
    vector<int> x; //存放当前解
    vector<int> bestx; //当前最优解

public:
    int maxLoading(vector<int> &ww,int cc){
        n = ww.size()-1;
        w = ww;
        c =cc;
        cw = 0;
        bestw = 0;
        r=0;
        for (int i = 1; i <=n; ++i) {
            r +=w[i];//初始化 r
        }
        for (int i = 0; i <=n; ++i) {
            x.push_back(0);
            bestx.push_back(0);//初始化
        }

        backtrace(1);
        return  bestw;
    }

    void backtrace(int t){
        if(t>n){
            if(cw >  bestw) {
                for (int i = 1; i <=n; ++i) {
                    bestx[i] = x[i];//动态更新
                }
                bestw = cw; // output -最优
            }
            return;
        }

            //搜索左右子树 -> 装或不装
            r-=w[t];//剩余 集装箱重量
            if(cw+w[t]<=c){
                x[t] = 1;//选
               cw = cw+w[t];
                backtrace(t+1);//搜索左子树
                cw-=w[t];//回溯
            }
            // 如果剩余重量 + cw < bestw 就不用装了，因为不会是最优解
            if(r+cw>bestw){
                x[t] = 0;
                backtrace(t+1);
            }
            r+=w[t];//回溯

    }

};






int main(){
    Loading l;
    vector<int> v(11);
    for (int i = 1; i <=10; ++i) {
        v[i] = rand() % 51 + 50;
    }

    for (int i = 1; i <=10; ++i) {
        cout << v[i]  << " ";
    }
    cout << endl;

    int x = l.maxLoading(v,125);
    cout << x << endl;



    return 0;
}

