//
// Created by ellen on 2022-03-14.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#include <stdio.h>
vector<int> div(vector<int>A ,int B,int &R){
    vector<int> C;
    R =0;
    for (int i = A.size()-1; i >=0; --i) {
        R = R*10 + A[i];
        C.push_back(R/B);//上商
        R = R % B;//余数
    }
    reverse(C.begin(), C.end());
    while (C.size()>1 && C.back()==0) C.pop_back();
    return C;
}

int main ()
{
    vector<int> A;
    int B;
    int R;//把地址丢进去，直接外部返回修改的值
    string a;
    cin >> a >> B;
    for (int i = a.length()-1; i>=0; --i) {
        A.push_back(a[i]-'0');
    }
    vector<int> C = div(A,B,R);

    for (int i = C.size()-1; i>=0; --i) {
        printf("%d ",C[i]);
    }
    cout << endl << R << endl;
    return 0;
}
