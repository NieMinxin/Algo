//
// Created by ellen on 2022-03-17.
//

#include <iostream>
using namespace std;

string replaceSpaces(string &str) {
    string res;
    int len = 0;
    for (auto  c:res) {
        if(c==' '){
            len+=3;
        } else{
            len++;
        }
    }
    str.resize(len);
    int j = len-1,i=str.size()-1;
    while (i>=0){
        if(i==' '){
            str[j--] = '0';
            str[j--] = '2';
            str[j--] = '%';
        } else{
            str[j--] = str[i];
        }
        i--;
    }
    return str;
}

int main ()
{

    return 0;
}
