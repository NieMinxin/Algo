//
// Created by ellen on 2022-05-08.
//
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
const int N =1000010;

char a[N];
string ll[5][10] = {
{"***",".*.","***","***","*.*","***","***","***","***","***"},
{"*.*",".*.","..*","..*","*.*","*..","*..","..*","*.*","*.*"},
{"*.*",".*.","***","***","***","***","***","..*","***","***"},
{"*.*",".*.","*..","..*","..*","..*","*.*","..*","*.*","..*"},
{"***",".*.","***","***","..*","***","***","..*","***","***"}
};


int main(){

    string l;
    std::getline(std::cin, l, '\n');

    string ls[5];

        for (int j = 0; j < 5; ++j) {
            for (int k = 0;l[k]; ++k) {
                ls[j] +=ll[j][l[k]-'0'];
                ls[j]+=".";
            }
        }

    for (int i = 0; i < 5; ++i) {
        cout << ls[i] <<endl;
    }
    return 0;
}