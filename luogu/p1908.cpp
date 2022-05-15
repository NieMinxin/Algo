//
// Created by ellen on 2022-03-19.
//

#include <iostream>
using namespace std;
const int N = 500010;
int tmp[N];
int res = 0;
int merge(int arr[],int l,int r){
    if(l>=r){return 0;}

    int mid = (l+r)>>1;

    res=merge(arr,l,mid) + merge(arr,mid+1,r);

    int i=l,j= mid+1;
    while (i<=mid && j<=r){
        if(arr[i]>arr[j]){
            res+= mid-i+1;
            j++;
        }else{
            i++;
        }
    }

    int k =0;
    i = l,j = mid+1;
    // i是左边
    while (i<=mid && j <=r){
        if(arr[i]<= arr[j]){
            tmp[k++] = arr[i++];
        } else{
            tmp[k++] = arr[j++];
        }
    }
    while (i<=mid){
        tmp[k++] =arr[i++];
    }
    while (j<=r){
        tmp[k++] =arr[j++];
    }

    for (int i = l,j=0; i<=r ; ++i,++j) {
        arr[i] = tmp[j];
    }
    return res;
}
int main(){

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >>arr[i];
    }
    int v = merge(arr,0,n-1);
    cout << v ;
    return 0;
}