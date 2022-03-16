//
// Created by ellen on 2022-03-13.
//

#include <iostream>

using namespace std;

#include <stdio.h>
typedef struct Element{
    float weight;
    float value;
    float average;
    int index;
}Item;

void quick_sort(Item arr[],int l, int r){
    if(l>=r){
        return;
    }

    float pivot = arr[l].average ;
    int i=l-1,j=r+1;
    while (i<j){
        do i++; while (arr[i].average<pivot);
        do j--; while (arr[j].average>pivot);
        if(i<j) swap(arr[i],arr[j]);
    }
    quick_sort(arr,l,j);
    quick_sort(arr,j+1,r);
}


float  knapsack(float C,float w[],float v[],float x[],int n){
    //n ,代表物品个数
    Item  items[n];
    for (int i = 0; i < n; ++i) {
        items[i].value=v[i];
        items[i].index = i;
        items[i].weight = w[i];
        items[i].average = v[i]/w[i];
    }

    quick_sort(items,0,n-1);
    float  opt = 0;
    for (int i = 0; i < n; ++i) {
        x[i] = 0;//初始化
    }
    int i=0;
    for (i = 0; i < n; ++i) {
        if(items[i].weight > C) break;
        x[items[i].index] = i;
        opt +=items[i].value;
        C-=items[i].weight;
    }
    if(i<n){
        x[items[i].index]=C/items[i].weight;//C /weight,剩余重量全部装入背包
        opt+=x[items[i].index]*items[i].value;//计算价值
    }
    return opt;
}

int main ()
{



    return 0;
}