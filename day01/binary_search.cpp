//
// Created by ellen on 2022-03-08.
//

#include <iostream>
#include <vector>
using namespace std;
int binary_search(vector<int> &arr,int target){
    int start = 0,end= arr.size()-1;
    while(start< end){
        int mid = start + end >>1;
        if(arr[mid]>target){
            start = mid+1;
        } else if(arr[mid] < target){
            end = mid -1;
        } else{
            return  mid;
        }
    }
    return  -1;
}

int main ()
{

    return 0;
}