#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    long long p = 0, q = 0, r = 1;

    for(int i = 1;i<=n;i++){
       p = q;
       q = r;
       r = p+q;
    }

    int a[3];
    scanf("%s",a);
    printf("%c",a[0]);

    printf("%lld",r);
    return 0;
}