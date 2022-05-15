//
// Created by ellen on 2022-04-24.
//
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> a;
vector<int> b;
vector<int> c;
int main(){
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int t;
        scanf("%d",&t);
        a.push_back(t);
    }
    for (int i = 0; i < m; ++i) {
        int t;
        scanf("%d",&t);
        b.push_back(t);
    }
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int i = 0,j = 0;

    while(i<a.size() && j<b.size()){
        if(a[i]<=b[j]){
            c.push_back(a[i]);
            i++;
        }else{
            c.push_back(b[j]);
            j++;
        }
    }
    int k = (i==a.size()) ? j : i;
    if(k==j){
        while(k<b.size()){
            c.push_back(b[k]);
            k++;
        }
    } else{
        while(k<a.size()){
            c.push_back(a[k]);
            k++;
        }
    }

    for (int l = 0; l < c.size(); ++l) {
        printf("%d ",c[l]);
    }
    return 0;
}