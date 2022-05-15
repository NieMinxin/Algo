//
// Created by ellen on 2022-03-18.
//

#include <iostream>
using namespace  std;
const int N = 100010;
int a[N],b[N];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);

    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }

    for (int i = 0; i < m; ++i) {
        scanf("%d",&b[i]);
    }

    int i=0,j=0;
    while (i<n && j<m){
        if(a[i]==b[j]){
            i++;
            j++;
        } else{
            j++;
        }
    }
    if(i<n){
        printf("No\n");
    }else{
        printf("Yes\n");
    }
    return 0;

}