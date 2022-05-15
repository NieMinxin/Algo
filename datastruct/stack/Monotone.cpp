//
// Created by ellen on 2022-05-15.
//
#include <iostream>
using namespace std;
const int N = 3000010;
int a[N],res[N];
#include<stack>
#include<algorithm>


int main(){
    int n;
    cin >> n;
    stack<int> stk;
    for (int i = 1; i<=n; ++i) {
        scanf("%d",&a[i]);
    }

    for(int i=n;i>=1;--i){
        while(!stk.empty() && a[stk.top()]<=a[i]){
            stk.pop();
        }
        if(stk.empty()){
            res[i] = 0;
        }else{
            res[i] = stk.top();
        }
        stk.push(i);
    }

    for(int i=1;i<=n;i++){
        printf("%d ",res[i]);
    }
    return 0;
}