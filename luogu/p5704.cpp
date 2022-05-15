//
// Created by ellen on 2022-03-18.
//

#include <iostream>

using namespace std;
const int N =1000;
int a[N];
int A[2000000];
int main(){
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < m; ++i) {
        scanf("%d",&A[i]);
        a[A[i]]++;
    }

    for (int i = 1; i <=N-1; ++i) {
        for (int j = 0; j < a[i]; ++j) {
            printf("%d ",i);
        }
    }
    return 0;
}