//
// Created by ellen on 2022-03-14.
//
#include<iostream>
using namespace std;
int main(){
    int n,m;
    int a[n+1],s[n+1];
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        s[i] = s[i-1]+a[i];//初始化S[]
    }
    while(m--){
        int l,r;
        scanf("%d%d",&l,&r);
        printf("%d\n",s[r]-s[l-1]);
    }

}
