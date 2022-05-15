//
// Created by ellen on 2022-04-06.
//

#include<iostream>
using namespace std;
const int N = 50010;
int p[N];
int size1[N];
// 返回集合的根节点 ，并且路径压缩
int find(int x){
    if(p[x]!=x) p[x] = find(p[x]);
    return p[x];
}
int main(){
    int n,m;
    cin >> n >>m;
    //初始化每一个数 为单独的集合
    for(int i=1;i<=n ;i++){
        p[i] = i;
        size1[i]=1;
    }
    while(m--){
        char op[3];// 如果为 char ，scanf 不会忽略空格
        int a,b;
        scanf("%s",op);
        if(op[0]=='C'){
            scanf("%d%d",&a,&b);
            p[find(a)] = find(b);//合并并查集
            size1[find(a)] + size1[find(b)];
        }else if(op[0]=='Q'){
            if(op[1]='1'){
                scanf("%d%d",&a,&b);
                if(find(a)==find(b))
                    puts("Yes");
                else
                    puts("No");
            }
            else{
                scanf("%d",&a);
                printf("%d",size1[find(a)]);
            }
        }
    }
    return 0;
}