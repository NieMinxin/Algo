//
// Created by ellen on 2022-04-10.
//

//
// Created by ellen on 2022-04-10.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

    vector<string> res;
    void dfs(string s, int x) {
        if(x == s.size() - 1) {
            res.push_back(s);                       // 添加排列方案
            return;
        }
        set<char> st;
        for(int i = x; i < s.size(); i++) {
            if(st.find(s[i]) != st.end()) continue; // 重复，因此剪枝
            cout << s[i] << endl;
            st.insert(s[i]);
            swap(s[i], s[x]);                       // 交换，将 s[i] 固定在第 x 位
            dfs(s, x + 1);                          // 开启固定第 x + 1 位字符
            swap(s[i], s[x]);                       // 恢复交换
        }
    }

vector<string> permutation(string s) {
    dfs(s, 0);
    return res;
}


int main(){
    string s;
    getline(cin,s);
    permutation(s);
    return 0;
}

