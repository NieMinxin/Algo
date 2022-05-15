#include <iostream>
using namespace std;
int b[101][101];//表征c[][]数组的局部关系
int c[101][101];//表征x{0-i}与y{0-j}的最长公共子序列的长度
//LSC函数完成对b，c数组的填充
void LSC(int m,int n,char *x,char *y)
{
    //当其中一个字符串为空串时，最长公共子序列的长度为0
    for(int i=0;i<=m;i++) c[i][0]=0;
    //当其中一个字符串为空串时，最长公共子序列的长度为0
    for(int j=0;j<=n;j++)  c[0][j]=0;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++){
            if(x[i]==y[j])//第一种情况
            {c[i][j]=c[i-1][j-1]+1;b[i][j]=1;}
            else if(c[i-1][j]>c[i][j-1])//第二种情况
            {c[i][j]=c[i-1][j];b[i][j]=2;}
            else                        //第三种情况
            {c[i][j]=c[i][j-1];b[i][j]=3;}
        }
}
//PrintLSC函数借助b数组的值递归调用打印出最长公共子序列
void PrintLSC(int i,int j,char*x,char*y)
{
    if(i==0||j==0) return;
    if(b[i][j]==1)
    {PrintLSC(i-1,j-1,x,y);cout<<x[i];}
    else if(b[i][j]==2)
        PrintLSC(i-1,j,x,y);
    else
        PrintLSC(i,j-1,x,y);
}
int main()
{
    int m,n;
    cin>>m>>n;//用来表示字符串x,字符串y的长度
    char *x = new char[m+1];
    char *y = new char[n+1];
    for(int i=1;i<=m;i++){
        cin>>x[i];
    }
    for(int i=1;i<=n;i++){
        cin>>y[i];
    }
    LSC(m,n,x,y);
    PrintLSC(m,n,x,y);
    return 0;
}