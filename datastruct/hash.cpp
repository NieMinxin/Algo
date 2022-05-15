//
// Created by ellen on 2022-04-08.
//

#include <iostream>
#include <cstring>

using namespace std;

/*
int prime(){
    for (int i = 100000;; ++i) {
        bool flag = true;
        for (int j = 2; j*j <=i ; ++j) {
            if(i%j==0){
                flag = false;
                break;
            }
        }
        if(flag) return i;
    }
}
*/

const int N = 100003;
int h[N],e[N],ne[N],idx;

void insert(int x){
    int hash = (x % N + N) % N; // 将负数转化为正数
    //头插法
    e[idx] = x ;//链表保存
    ne[idx] = h[hash];// 指向头节点
    h[hash] = idx;// 存的是某一个节点
    idx++; //
}

bool find(int x){
    int hash = (x % N + N) % N; // 将负数转化为正数
    for(int i=h[hash];i!=-1;i=ne[i]){
        //-1 代表空 null
        if(e[i]==x){
            return true;
        }
    }
    return false;
}

int main(){
    memset(h,-1,sizeof  h);//初始化
    int n;
    cin >> n;

    while (n--){

        char op[2];
        int v;
        scanf("%s%d",op,&v);
        if(*op=='I') insert(v);
        else{
            if(find(v)) printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}