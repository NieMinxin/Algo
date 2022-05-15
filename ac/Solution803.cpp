//
// Created by ellen on 2022-03-22.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int N = 100010;
vector<pair<int,int>> a;
int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int l,r;
        cin >> l>>r;
        a.push_back({l,r});
    }
    if(a.size()==0){
        printf("%d",0);
        return 0;
    }
    std::sort(a.begin(), a.end());
    vector<pair<int,int>> c;
    int start=INT32_MIN,end=INT32_MIN;
    for (int i = 0; i < a.size(); ++i) {
        if(end<a[i].first){
            if(start!=INT32_MIN) c.push_back({start,end});
            start = a[i].first,end=a[i].second;
        } else{
            end = max(end,a[i].second);
        }
    }
    //处理最后一次
    if(start!=INT32_MIN){
        c.push_back({start,end});
    }

    printf("%d",c.size());
    return 0;
}