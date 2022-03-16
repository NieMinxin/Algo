//
// Created by ellen on 2022-03-04.
//

#include <iostream>
#include <vector>
using namespace  std;
const int N = 1e+6;
int tmp[N];
int a[N];
typedef long long LL;
LL res =0;

LL merge(vector<int> &nums,int l,int r){
    if(l>=r){return 0;}

    int mid = (l+r)>>1;

    int n1=merge(nums,l,mid);
    int n2 = merge(nums,mid+1,r);
    res = n1+n2;

    int k =0, i = l,j = mid+1;
    // i是左边
    while (i<=mid && j<=r){
        if(nums[i]<= nums[j]){
            tmp[k++] = nums[i++];
        } else{
            if(nums[i] > 2*nums[j]){
                res+=mid-i+1;
            }
            tmp[k++] = nums[j++];
        }
    }
    while (i<=mid){
        tmp[k++] =nums[i++];
    }
    while (j<=r){
        tmp[k++] =nums[j++];
    }

    for (int i = l,j=0; i<=r ; ++i,++j) {
        nums[i] = tmp[j];
    }

    return res;
}


LL  merge_sort(int arr[], int l, int r){
    if(l>=r){return 0;}

    int mid = (l+r)>>1;

    res=merge_sort(arr,l,mid) + merge_sort(arr,mid+1,r);

    int k =0, i = l,j = mid+1;
    // i是左边
    while (i<=mid && j <=r){
        if(arr[i]<= arr[j]){
            tmp[k++] = arr[i++];
        } else{
            res += mid -i + 1;//???  每次归并都是排好序，这样小的在前面
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

//当你发现 4 比 3 大的时候，也就是说右边最大的元素都小于左边最小的元素，
// 那么左边剩下的5和6都必然比右边的所有元素大，因此就可以不用数5和6的情形了，
// 直接分别加上右半边的元素个数就可以了，这一步就降低到了
int main ()
{
    int n;
    scanf("%d",&n);

    for (int i = 0; i < n; ++i) {
        scanf("%d",&a[i]);
    }
   cout << merge_sort(a,0,n-1) << ends;
    return 0;
}

//typedef long long LL;
//LL res =0;

int reversePairs(vector<int>& nums) {
    return merge(nums,0,nums.size()-1);
}



