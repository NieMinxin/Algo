
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
struct point{
    double x,y;
}p[10010];
const int n,temp[10010];

bool cmp(const point &A,const point &B)
{
    if(A.x==B.x)
        return A.y<B.y;
    else
        return A.x<B.x;
}

bool cmpS(const int &a,const int &b)
{
    //比较y坐标
    return p[a].y<p[b].y;
}

double distance(int i,int j)
{
    double  d = sqrt((p[i].x-p[j].x)*(p[i].x-p[j].x)+(p[i].y-p[j].y)*(p[i].y-p[j].y));
    return d;
}


double merge(int l,int r){
    double  dist = INT32_MAX;
    if(r==l){
        return dist;
    }
    //两个元素
    if(l+1==r){
        return distance(l,r);
    }

    //分
    int mid = (l+r)>>1;
    double d1=merge(l,mid);
    double d2=merge(mid+1,r);
    dist = min(d1,d2);//比较

    //合
    int k = 0;
    for (int i = l; i <=r ; ++i) {
        if(fabs(p[i].x-p[mid].x)<=dist){//double
            temp[k++]=i;//加入到新的集合中
        }
    }
    //对坐标Y排序
    sort(temp,temp+k,&cmpS);

    for (int i = 0; i < k; ++i) {
        for (int j = i+1;j < k && p[temp[j]].y-p[temp[i]].y<dist;++j) {
            dist = min(dist, distance(temp[i],temp[j]));
        }
    }
    return dist;
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        scanf("%lf%lf",&p[i].x,&p[i].y);
    }
    //对x 排序
    sort(p,p+n,&cmp);
    double  dis = merge(0,n-1);
    printf("%.4lf\n",dis);
    return 0;
}