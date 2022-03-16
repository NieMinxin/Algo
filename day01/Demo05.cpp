//
// Created by ellen on 2022-03-08.
//
#include <iostream>

using namespace std;
const int N = 100000;
int q[N];
int main ()
{
    int n,m;
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; ++i) {
        scanf("%d",&q[i]);
    }

    while (m--){
        int x;
        scanf("%d",&x);
        int l =0,r = n-1;
        while (l<r){
            int mid  = l+r>>1;
            if(q[mid]>=x) r = mid;
            else l = mid+1;
        }
        //循环到后面 l=r,并且找到这个数
        if(q[l]!=x){
            cout << "-1 -1" << endl;
        } else{

            cout<< l << ' ' ;

            int l = 0 , r=n-1;
            while (l<r){
                int mid = l+r+1>>1;
                if(q[mid]<=x) l = mid;
                else r = mid-1;
            }

            cout << l << endl;
        }
    }
    return 0;
}
