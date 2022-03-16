//
// Created by ellen on 2022-03-13.
//

//活动安排问题

#include <iostream>
using namespace  std;
void quick_sort(int s[],int f[],int l, int r){
    if(l>=r){
        return;
    }

    int pivot = f[l] , i=l-1,j=r+1;
    while (i<j){
        do i++; while (f[i]<pivot);
        do j--; while (f[j]>pivot);
        if(i<j){
            swap(f[i],f[j]);
            swap(s[i],s[j]);
        }
    }
    quick_sort(s,f,l,j);
    quick_sort(s,f,j+1,r);
}


int greedy(int s[],int f[],int k,bool isR[]){

    isR[1] = true;
    int count=1;
    int j =1;//指针指向 上一个安排活动的结束时间
    for (int i = 2; i <=k; ++i) {
        if(s[i]>=f[j]){
            isR[i] = true;
            count++;
            j = i;
        } else{
            isR[i] = false;
        }
    }

    return count;

}

int main ()
{

    cout << "输入活动安排数:" <<endl;
    int n;
    scanf("%d",&n);
    int s[n];
    int f[n];
    bool b[n];//活动是否被安排

    cout << "请输入每个活动的开始时间(0-24):" << endl;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&s[i]);
    }

    cout << "请输入每个活动的结束时间(0-24):" << endl;
    for (int i = 0; i < n; ++i) {
        scanf("%d",&f[i]);
    }
    //初始化
    for (int i = 0; i < n; ++i) {
        b[i] = false;
    }

    quick_sort(s,f,0,n-1);//按照完成时间排序


    int sum = greedy(s,f,n,b);


    cout << "最大活动安排数量为:" << sum  << endl;


    return 0;
}
