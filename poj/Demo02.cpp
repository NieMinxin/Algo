//
// Created by ellen on 2022-05-08.
//
#include <iostream>
#include <algorithm>
using namespace std;
const int N =3010;
int a[N];
int main(){

    int n;

    scanf("%d",&n);
    for (int i = 0; i <n; ++i) {
        scanf("%d",&a[i]);
    }

    sort(a,a+n);

    int count =0;

    for (int first = 0; first < n; ++first) {
        // 需要和上一次枚举的数不相同
        if (first > 0 && a[first] == a[first - 1]) {
            continue;
        }
        // c 对应的指针初始指向数组的最右端
        int third = n - 1;
        int target = -a[first];
        // 枚举 b
        for (int second = first + 1; second < n; ++second) {
            // 需要和上一次枚举的数不相同
            if (second > first + 1 && a[second] == a[second - 1]) {
                continue;
            }
            // 需要保证 b 的指针在 c 的指针的左侧
            while (second < third && a[second] + a[third] > target) {
                --third;
            }
            // 如果指针重合，随着 b 后续的增加
            // 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
            if (second == third) {
                break;
            }
            if (a[second] + a[third] == target) {
                count++;
            }
        }
    }

    printf("%d",count);
    return 0;
}