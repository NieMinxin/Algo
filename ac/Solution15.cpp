//
// Created by ellen on 2022-03-17.
//

#include <iostream>

using namespace std;
#include <vector>

bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    int n = matrix.size()-1;
    int m = matrix[0].size()-1;
    if(matrix.empty() || matrix[0].empty()) return false;
    int r = 0,c = m;
    while (r<=n && c>=0){
        if(matrix[r][c]==target) return true;
        else if(matrix[r][c]>target) c--;
        else r++;
    }
    return false;
}
int main ()
{

    return 0;
}