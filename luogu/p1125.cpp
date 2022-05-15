//
// Created by ellen on 2022-03-19.
//

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <math.h>
using namespace std;

int p(int a)//判断maxn-minn是否为质数
{
    int i;
    if(a==0) return 0;
    if(a==1) return 0;//如果maxn-minn为1或0的结果
    for(i=2;i*i<=a;i++)
        if(a%i==0) return 0;
    return 1;
}

int main(){
    int max,min=100;
    unordered_map<char,int> map;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        map[s[i]]++;
        if(map[s[i]] > max){
            max = map[s[i]];
        }
    }
    unordered_map<char, int>::iterator  iter;
    for (iter = map.begin(); iter!=map.end(); iter++) {
        if(iter->second <=min){
            min = iter->second;
        }
    }

    int v = max-min;
    if(v==1||v==0){//这里要加个特判，因为质数的定义是“特别的，1不是质数”，当然，0也不是质数
        cout<<"No Answer\n0";
        return 0;//直接结束程序即可
    }
    if(p(v)){
        cout<<"Lucky Word"<<endl;
        cout<<v;
    } else{
        cout<<"No Answer\n0";
        return 0;//直接结束程序即可
    }


    return 0;
}