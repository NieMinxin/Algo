#include <iostream>
#include <algorithm>
using namespace std;
const int N  = 100010;
int a[N];
int len;

void down(int x){
    int t = x;
    if( 2*x <=len && a[x] > a[2*x]) t = 2*x;
    if(2*x+1<=len && a[t] > a[2*x+1]) t = 2*x+1;
    if(t!=x){
        swap(a[t],a[x]);
        down(t);//继续递归
    }

}

int main(){

    int n,m;
    cin >> n;
    for (int i = 1; i <=n ; ++i) {
        scanf("%d",&a[i]);
    }
    len = n;

    //建堆
    for (int i = n/2; i; i--) {
        down(i);
    }

    //堆排序
    for (int i = 1; i <=n; ++i) {
        swap(a[1],a[len]);
        len--;//先 删除，减少执行
        down(1);
    }


    for (int i = n; i>=1 ; i--) {
        cout << a[i] << endl;
    }
    return 0;
}