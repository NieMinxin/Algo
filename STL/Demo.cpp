//
// Created by ellen on 2022-04-09.
//


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
string s;
vector<string> res;
void backtrace(string s,int i,int n){
    if(i==n) res.push_back(s);
    for(int k=i;i< n;i++){
        swap(s[i],s[k]);
        backtrace(s,k+1,n);
        swap(s[i],s[k]);
    }
}

int  cmp(string &s1,string &s2){
    for (int i = 0; i < s1.length(); ++i) {
        if(s1[i]!=s2[i]) return s1[i]-s2[i];
    }
    return  0;
}



int main(){

    cin >> s;
    backtrace(s,0,s.size());

    for( string t:res){
        cout << t << endl;
    }
    return 0;
}
