//
// Created by ellen on 2022-04-10.
//

// dp
#include<iostream>
using namespace std;
const int  N = 1010;
bool dp[N][N]; // 状态表示
int main(){

    string s;
    getline(cin, s);//读入空格
    int l = s.length(), ans = 1;
    //初始化
    for(int i=0;i<l;i++){
        dp[i][i] = true;

    }

    //从长度3开始枚举
    for(int len=2;len<=l;len++){
        for(int i=0;i+len-1<l;i++){
            //右端点
            int j = i+len -1;
            if((s[i]==s[j]) && dp[i-1][j+1]){ //判断是否为回文串
                dp[i][j] = true;
                if(dp[i][j])
                    ans=max(ans,j-i+1);
            }else{
                dp[i][j] =false;
            }

        }
    }

    printf("%d",ans);
    return 0;
}