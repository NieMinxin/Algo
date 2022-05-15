//
// Created by ellen on 2022-03-18.
//
#include <iostream>
using namespace std;
const int N = 100010;
int a[N],b[N];
int main(){
    int n,m,t;
    scanf("%d%d%d",&n,&m,&t);
    for (int i = 0; i <n; ++i) {
        scanf("%d",&a[i]);
    }
    for (int i = 0; i <m; ++i) {
        scanf("%d",&b[i]);
    }

    int i = 0,j=m-1;

    while (i<n && j>=0){
        if(a[i]+b[j]==t){
            break;
        } else if(a[i]+b[j]<t){
            i++;
        }else{
            j--;
        }
    }
    printf("%d%d",i,j);
    return 0;
}