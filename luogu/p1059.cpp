//
// Created by ellen on 2022-03-22.
//

#include <iostream>
#include <algorithm>
using namespace std;
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
    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; ++i) {
        cin >> a[i];
    }
    quick_sort(0,N-1,a);

    //双指针数组重复元素
    int i=0,j=0;
    while (i<N&& j <N){
        if(a[i]==a[i+1]){
            i++;
        } else{
            a[j++]=a[i++];
        }
    }

    printf("%d\n",j);
    for (int k = 0; k <j; ++k) {
        printf("%d ",a[k]);
    }

    return 0;
}