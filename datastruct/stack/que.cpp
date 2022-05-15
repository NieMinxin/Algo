//
// Created by ellen on 2022-05-15.
//
//
// Created by ellen on 2022-05-15.
//
#include <iostream>
using namespace std;
#include <queue>
#include <algorithm>

int main(){

    int n;
    cin >> n;
    queue<int> q;
    while(n--){

        string  op;
        int x;
        cin >> op;

        if(op=="push"){
            cin >> x;
            q.push(x);
        }else if(op=="query"){
            printf("%d\n",q.front());
        }else if(op=="pop"){
            q.pop();
        }else if(op=="empty"){
            bool t = q.empty();
            if(t){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }

    }
    return 0;
}