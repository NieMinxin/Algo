//
// Created by ellen on 2022-03-30.
//

#include <iostream>
using namespace std;

/*const int N=100;
int matrix[N][N],matrix1[N][N],matrix2[N][N];
int row1,row2,col1,col2;
void mul(){
    scanf("%d%d%d%d",&row1,&row2,&col1,&col2);

    if(col1!=row2){
                 fprintf(stderr,"enput error!");
                 exit(EXIT_FAILURE);
             }
         printf("The result:\n");
         for(int i=0;i<row1;i++){
                for(int j=0;j<col2;j++){
                        for(int k=0;k<col1;k++){
                                matrix[i][j]=matrix[i][j]+matrix1[i][k]*matrix2[k][j];
                        }
                }
         }
}*/
const int N = 10000;
int p[N];
int m[N][N],s[N][N];
void dp_mul(){

    //m记录状态，s用来构造最优解
    int n ;
    scanf("%d",&n);//矩阵的行列
    for (int i = 0; i <n; ++i) {
        scanf("%d",&p[i]);
    }
    n = n-1;
    // 自底 向上
    for (int i = 1; i <=n-1; ++i) {
        m[i][i] = 0;//初始化
    }
    for (int l = 2; l <=n; ++l) {
        // n-1 行
        int i;
        int j;
        for (i = 1; i <=n-l+1; ++i) {
            // 每一行 多少个元素，前面的不用乘
            j = i+l-1;// 每一行从大于1的元素开始计算 乘法
            m[i][j] = m[i+1][j] + p[i-1]*p[i]*p[j];// 列相等
            //初始化此时在i处取得最优解
            s[i][j] = i;

            // 开始切分
            for (int k = i+1; k<j;++k) {
                m[i][j] = min(m[i][j],m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j]);
                s[i][j]=k;//切分
            }
        }


    }

}
void back_trace(int s[][N],int i,int j){
    if(i==j){
        cout << "A" << i;
    }else{
        cout << "(";
        back_trace(s,i,s[i][j]);
        back_trace(s,s[i][j]+1,j);
        cout << ")";
    }
}

int main(){


    return 0;
}