//
// Created by ellen on 2022-03-22.
//

#include <iostream>
using namespace std;
const int N = 100010;
int a[N],s[N];
int main(){
    int n,m;
    scanf("%d",&n);

    for (int i = 1; i <=n; ++i) {
        scanf("%d",&a[i]);
    }
    for (int i = 1; i <=n ; ++i) {
        s[i] = s[i-1]+a[i];
    }
    scanf("%d",&m);
    while (m--){
        int l,r;
        cin >> l >> r;
        printf("%d\n",s[r]-s[l-1]);
    }

    return 0;
}