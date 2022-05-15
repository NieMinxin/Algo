//
// Created by ellen on 2022-05-12.
//
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1010;
int a[N];

void quick_sort(int l,int r){

    if(l>=r){
        return; //没有数据 ，或者数据为1
    }

    int q = a[l];

    int i = l-1,j=r+1;

    while(i<j){
        do i++; while (a[i]<q);
        do j--;while(a[j]>q);
        if(i<j){
            swap(a[i],a[j]);
        }
    }
    quick_sort(l,j);
    quick_sort(j+1,r);
}

int main(){

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
    quick_sort(0,n-1);

    bool ok = false;
    int min;
    if(a[0]==1){
        min = 0;
        ok = true;
    }else{
        min = a[0];
        for (int i = 1; i < n; ++i) {
            if(min==a[i] || min+1==a[i]){
                min = a[i];
            }else{
                min = min + 1;
                ok = true;
                break;
            }
        }
    }

    if(ok){
        printf("%d",min);
    }else{
        printf("%d",min+1);
    }

    return 0;
}