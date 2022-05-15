//
// Created by ellen on 2022-03-22.
//

#include <iostream>
using namespace std;
#include <algorithm>
const int N = 5000010;
int a[N];

void quick_sort(int l,int r,int arr[]){
    if(l>=r){return;}
    int k = arr[l];
    int i=l-1,j=r+1;

    while (i<j){
        do i++; while (arr[i]<k);
        do j--; while (arr[j]>k);
        if(i<j)swap(arr[i],arr[j]); //有可能指针 移过
    }

    quick_sort(l,j,arr);
    quick_sort(j+1,r,arr);
}


int main(){
    int n,i;
    scanf("%d%d",&n,&i);
    for (int j = 0; j < n; ++j) {
        scanf("%d",&a[j]);
    }

    quick_sort(0,n-1,a);
    printf("%d",a[i]);


    return 0;
}