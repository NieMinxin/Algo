//
// Created by ellen on 2022-03-19.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace  std;
typedef pair<int, int> PII; // 边界
const int N = 300010; //10e5 个数 ，要映射到索引，20e5个index 询问
int a[N], s[N];
vector<int> alls;//存放索引
vector<PII> add, query;// 一个时添加值，一个获取询问

//查找索引
int find(int x){
    int l=0 ,r= alls.size()-1;
    while (l<r) {
        int mid = l + r >> 1;
        if (alls[mid] >= x) r = mid;
        else l = mid +1;
    }
    return r+1;
}

int main(){
    int n,m;
    cin >> n >> m;

    for (int i = 0; i < n; ++i) {
        int x,c ;//操作
        cin >> x >> c;
        add.push_back({x,c});//添加到 add
        alls.push_back(x); // index 添加到 alls ，alls 用来存放索引，然后映射
    }
    for (int i = 0; i < m; ++i) {
        int l,r;
        cin >> l >> r;
        query.push_back({l, r});//询问
        alls.push_back(l);
        alls.push_back(r);
    }

    //去重 ---双指针算法
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());

    //处理输入
    for(auto v:add){
        int x = find(v.first);
        a[x] += v.second;
    }

    //构造前缀和
    for (int i = 1; i <=alls.size(); ++i) {
        s[i] = s[i-1]+a[i];
    }

    for(auto item:query){
        int l = find(item.first),r = find(item.second);
        cout << s[r] - s[l - 1] << endl;
    }


    return 0;
}