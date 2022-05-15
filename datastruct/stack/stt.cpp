//
// Created by ellen on 2022-05-15.
//
#include <iostream>
using namespace std;
#include <stack>
#include <algorithm>

int main(){

    int n;
    cin >> n;
    stack<int> s;
    while(n--){

        string  op;
        int x;
        cin >> op;

        if(op=="push"){
            cin >> x;
            s.push(x);
        }else if(op=="query"){
            printf("%d\n",s.top());
        }else if(op=="pop"){
            s.pop();
        }else if(op=="empty"){
            bool t = s.empty();
            if(t){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }

    }
    return 0;
}