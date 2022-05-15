
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 30;
int dp[N][N];
int s[N][N];
vector<char> res;

void LCS(vector<char> str,int i,int j,int d[][N]){
    if(i==0 || j==0)
        return;
    if(d[i][j]==1){
        LCS(str,i-1,j-1,d);
        res.push_back(str[i-1]);
    }else if(d[i][j]==2){


        LCS(str,i,j-1,d);
    }else
        LCS(str,i-1,j,d);




}
char str1[30],str2[30];
int main(){
    vector<char> s1,s2;
    scanf("%[^\n]",str1);
    getchar();
    scanf("%[^\n]",str2);
    getchar();
    int x=0;
    while (str1[x]){
        if(str1[x]!=' '){
            s1.push_back(str1[x]);
        }
        x++;
    }
    x = 0;
    while (str2[x]){
        if(str2[x]!=' '){
            s2.push_back(str2[x]);
        }
        x++;
    }
    int n = s1.size();
    int m = s2.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {

            if(dp[i][j+1]>=dp[i+1][j]){
                dp[i+1][j+1] = dp[i][j+1];
                s[i+1][j+1] = 3;
            }else{
                dp[i+1][j+1] = dp[i+1][j];
                s[i+1][j+1] = 2;
            }
            if(s1[i]==s2[j]){
                dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+1);
                s[i+1][j+1] = 1;
            }
        }
    }
    LCS(s1,n,m,s);
    cout << "[";
    for (int i = 0; i < res.size(); ++i) {
        if(i!=res.size()-1){
            cout << "\'" << res[i] <<"\'" << ", ";
        }else{
            cout << "\'" << res[i] <<"\'" ;
        }
    }
    cout << "]";
    return 0;
}