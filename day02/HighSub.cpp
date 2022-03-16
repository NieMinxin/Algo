//
// Created by ellen on 2022-03-10.
//
#include <iostream>
#include <vector>
using namespace std;

bool cmp(vector<int> &A,vector<int> &B){
    if(A.size()!=B.size()) return A.size() > B.size();
    for(int i = A.size() - 1; i >= 0; i --){
        if(A[i]!=B[i]){return A[i]-B[i];}
    }
    return true;//相等
}

vector<int> sub(vector<int> &A,vector<int> &B){
    vector<int> C;
    int t =0;//借位标志
    //A为较大的数
    for(int i=0;i<A.size();i++){
        t = A[i] - t;//借位
        if(i<B.size()) t-=B[i];
        C.push_back((t+10)%10);
        if(t<0) t=1;
        else t=0;
    }

    //消除高位的0 ,保留一位
    while(C.size()>1 && C.back()==0) C.pop_back();
    return C;
}
//高精度减
int main(){

    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for (int i = a.size() - 1; i >= 0; i -- ) A.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i -- ) B.push_back(b[i] - '0');
    vector<int> C;
    if(cmp(A,B)){
        C = sub(A,B);
        for (int i = C.size() - 1; i >= 0; i -- ) cout << C[i];//输出
    }else{
        C = sub(B,A);
        printf("-");
        for (int i = C.size() - 1; i >= 0; i -- ) cout << C[i];//输出
    }

    return 0;
}
