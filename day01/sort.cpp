//
// Created by ellen on 2022-03-04.
//
//
#include <iostream>
using  namespace std;

const int N = 10000;
int tmp[N];

void quick_sort(int arr[],int l, int r){
    if(l>=r){
        return;
    }

    int pivot = arr[l] , i=l-1,j=r+1;
    while (i<j){
        do i++; while (arr[i]<pivot);
        do j--; while (arr[j]>pivot);
        if(i<j) swap(arr[i],arr[j]);
    }
    quick_sort(arr,l,j);
    quick_sort(arr,j+1,r);
}

void merge_sort(int arr[],int left,int right){

        if(left>=right){
            return;
        }
        int mid = left+right>>1;
    merge_sort(arr,left,mid);
    merge_sort(arr,mid+1,right);



    //复原 ，合并
    int k=0,i = left ,j = mid+1;
    while (i<=mid && j <=right){

        if(arr[i]<=arr[j]){
            tmp[k++] = arr[i++];
        } else {
            tmp[k++] = arr[j++];
        }
    }
    while (i<=mid){
        tmp[k++] = arr[i++];
    }
    while (j<=right){
        tmp[k++] = arr[j++];
    }
    for (int i = left,j=0; i <=right ; ++i,++j) {
        arr[i] = tmp[j];
    }
}


int main ()
{
    int n;
    int k;
    scanf("%d %d",&n,&k);
    int arr[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d",&arr[i]);
    }
    merge_sort(arr,0,n-1);
    printf("%d",arr[k-1]);
    return 0;
}