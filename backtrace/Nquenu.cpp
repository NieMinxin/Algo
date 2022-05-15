//
// Created by ellen on 2022-04-13.
//

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
const int N  = 9;

// 输出八皇后的方案个数
/*class Solution {
public:
    int res=0;

    int totalNQueens(int n) {
        int x[n+1];//保存当前解，保存的 是 某一行的 皇后放置在那一列
        for(int i=1;i<=n;i++){
            x[n] =0;
        }
        backtrace(1,n,x);
        return res;
    }
    bool place(int k,int x[]){
        // 约束条件 ，这里必须和 之前的每一行比较
        for(int i=1;i<k;i++){
            if(abs(i-k)==abs(x[i]-x[k]) || x[i]==x[k]){
                return false;
            }
        }
        return true;
    }
    void backtrace(int k,int n,int x[]){
        if(k>n){
            res ++;
        } else{
            //每行枚举
            for (int i = 1; i <=n; ++i) { // 还没搜索的节点  ，N皇后为 N叉树的解空间
                x[k] = i;// 第 K 行 每列试一次 ，不行就 剪枝
                if(place(k,x)){
                    backtrace(k+1,n,x);
                }
            }
        }

    }
};*/

bool place(int k,int x[]){
    //枚举之前的行 ，看是否满足约束条件
    for(int i=1;i<k;i++){
        if(abs(k-i)==abs(x[k]-x[i]) || x[k]==x[i]){
            return false;
        }
    }
    return true;
}

void backtrace(int t,int n,int x[]){
    if(t>n){
        //保存结果

        for(int i=1;i<=n;i++){
            int col = x[i];
            string s;
            for(int j=1;j<=n;j++){
                if(j==col){
                    s+='Q';
                }else{
                    s+='.';
                }
            }
            cout << s << endl;
        }
        cout << endl;

    }
    else{
        // 搜索 子节点
        for(int j=1;j<=n;j++){
            x[t] = j;
            //是否满足约束条件，继续搜索
            if(place(t,x)){
                backtrace(t+1,n,x);
            }
        }

    }

}

void  solveNQueens(int n) {

    int x[n+1];
    for(int i=1;i<=n;i++){
        x[i] = 0;//记录 每行的皇后放在 那一列
    }
    backtrace(1,n,x);

}


int main(){

    int n;
    cin >> n;
    solveNQueens(n);//

    return 0;
}