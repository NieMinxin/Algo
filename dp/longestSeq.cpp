//
// Created by ellen on 2022-04-03.
//

#include <iostream>
using namespace std;
#define  ARROW_CENTER  1
#define  ARROW_LEFT  2
#define ARROW_UP  3
const int N = 1010;
int dp[N][N];
char a[N],b[N];
int s[N][N];

void print_lcs(int s[][N],int i,int j,char x[]){
    if(i==0 || j==0)
        return;
    if(s[i][j]==ARROW_CENTER){
         print_lcs(s,i-1,j-1,x);
         printf("%c ",x[i]);
    }else if(s[i][j]==ARROW_LEFT){
        print_lcs(s,i,j-1,x);
    }else{
        print_lcs(s,i-1,j,x);
    }
}

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(),m=text2.size();
        int dp[n+1][m+1];
        for (int i = 0; i <=m; ++i) {
            dp[0][i] = 0;
        }
        for (int i = 0; i <=n; ++i) {
            dp[i][0] = 0;
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                dp[i+1][j+1] = max(dp[i][j+1],dp[i+1][j]);
                if(text1[i]==text2[j]){
                    dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+1);
                }
            }
        }
        return dp[n][m];
    }
};

int main(){
    int n,m;
    cin >> n >> m;
    scanf("%s%s",a+1,b+1); //
    for (int i = 1; i <=n ; ++i) {
        for (int j = 1; j <=m; ++j) {
            if(a[i]==b[j]){
                dp[i][j] = dp[i-1][j-1]+1;
                s[i][j] = ARROW_CENTER;//记录转移的状态
            } else{
                if(dp[i-1][j]>=dp[i][j-1]){
                    dp[i][j] = dp[i-1][j];
                    s[i][j] = ARROW_UP;
                } else{
                    dp[i][j] = dp[i][j-1];
                    s[i][j] = ARROW_LEFT;
                }
            }
        }
    }
    printf("%d\n",dp[n][m]);
    print_lcs(s,n,m,a);
    return 0;
}

