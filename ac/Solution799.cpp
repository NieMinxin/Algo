//
// Created by ellen on 2022-03-18.
//

#include<iostream>
#include<algorithm>
const int N =100010;
using namespace  std;

int a[N];
int s[N];
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    int res=0;

    for (int i = 0,j=0; i < n; i++) {
        s[a[i]]++;
        while (s[a[i]]>1){
            s[a[j]]--;
        }
        res =  max(res,j-i+1);
    }

    cout << res << endl ;
    return 0;
}