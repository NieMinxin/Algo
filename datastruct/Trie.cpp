//
// Created by ellen on 2022-04-06.
//

#include <iostream>
using namespace std;
const int N = 100010;
int son[N][26],cnt[N],idx;//cnt 存单词多少个
char str[N];
void insert(char str[]){
    int p =0;
    for (int i = 0; str[i]; ++i) {
        int c = str[i] - 'a';
        if(!son[p][c]){
            son[p][c] = ++idx;
        }
        p = son[p][c];
    }
    cnt[p] ++; //单词结尾
}

int find(char str[]){
    int p = 0;
    for (int i = 0; str[i]; ++i) {
        int c = str[i] - 'a';
        if(!son[p][c]){
            return 0;
        }
        p = son[p][c];
    }
    return cnt[p];//返回个数
}

int main(){

    int n;
    cin >> n;
    while(n--){
        char op;

        cin >> op >> str;
        if(op=='I'){
            insert(str);
        } else{
            printf("%d", find(str));
        }

    }

    return 0;
}