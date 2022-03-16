//
// Created by ellen on 2022-03-14.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> mul(vector<int> A,int B){
    vector<int> C;
    int t = 0;
    for (int i = 0; i < A.size(); ++i) {
        if(i<A.size()) t+=A[i]*B;
        C.push_back(t%10);
        t/=10;
    }
    if(t){
        C.push_back(t);
    }
    while (C.size()>1 && C.back()==0) C.pop_back();//消去0
    return C;
}

int main ()
{
    vector<int> A;
    int B;
    string a;
    cin >> a >> B;
    for (int i = a.length()-1; i>=0; --i) {
        A.push_back(a[i]-'0');
    }
    vector<int> C = mul(A,B);

    for (int i = C.size()-1; i>=0; --i) {
        printf("%d ",C[i]);
    }

    return 0;
}