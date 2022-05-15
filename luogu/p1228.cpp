#include<iostream>
using namespace std;

int a[2048][2048];
int tile=1;


int xa[1000000],xb[1000000],ya[1000000],yb[1000000];//一定要开大，否则会re
void board(int tr,int tc,int dr,int dc,int size)
{
    if(size==1)    return;
    int t=tile,s=size/2;
    tile++;
    if(dr<tr+s&&dc<tc+s)    board(tr,tc,dr,dc,s);
    else
    {
        a[tr+s-1][tc+s-1]=t;
        //存拐角处的横坐标
        if(xa[t]==0)            xa[t]=tr+s-1;
        else if(tr+s-1!=xb[t])    xb[t]=tr+s-1;
        else                    xa[t]=tr+s-1;
        //存拐角处的纵坐标
        if(ya[t]==0)            ya[t]=tc+s-1;
        else if(tc+s-1!=yb[t])    yb[t]=tc+s-1;
        else                    ya[t]=tc+s-1;
        board(tr,tc,tr+s-1,tc+s-1,s);
    }
    if(dr<tr+s&&dc>=tc+s)    board(tr,tc+s,dr,dc,s);
    else
    {
        a[tr+s-1][tc+s]=t;
        if(xa[t]==0)            xa[t]=tr+s-1;
        else if(tr+s-1!=xb[t])    xb[t]=tr+s-1;
        else                    xa[t]=tr+s-1;
        if(ya[t]==0)            ya[t]=tc+s;
        else if(tc+s!=yb[t])    yb[t]=tc+s;
        else                    ya[t]=tc+s;
        board(tr,tc+s,tr+s-1,tc+s,s);
    }
    if (dr>=tr+s&&dc<tc+s)    board(tr+s,tc,dr,dc,s);
    else
    {
        a[tr+s][tc+s-1]=t;
        if(xa[t]==0)            xa[t]=tr+s;
        else if(tr+s!=xb[t])    xb[t]=tr+s;
        else                    xa[t]=tr+s;
        if(ya[t]==0)            ya[t]=tc+s-1;
        else if(tc+s-1!=yb[t])    yb[t]=tc+s-1;
        else                    ya[t]=tc+s-1;
        board(tr+s,tc,tr+s,tc+s-1,s);
    }
    if(dr>=tr+s&&dc>=tc+s)    board(tr+s,tc+s,dr,dc,s);
    else
    {
        a[tr+s][tc+s]=t;
        if(xa[t]==0)            xa[t]=tr+s;
        else if(tr+s!=xb[t])    xb[t]=tr+s;
        else                    xa[t]=tr+s;
        if(ya[t]==0)            ya[t]=tc+s;
        else if(tc+s!=yb[t])    yb[t]=tc+s;
        else                    ya[t]=tc+s;
        board(tr+s,tc+s,tr+s,tc+s,s);
    }
}
void print()
{
    for(int i=1;i<=tile-1;i++)//按编号先打印横纵坐标，然后判断形状
    {
        int x=xa[i],y=ya[i];
        cout<<x<<' '<<y<<' ';
        if(a[x-1][y]==i&&a[x][y-1]==i)         cout<<1<<endl;
        else if(a[x-1][y]==i&&a[x][y+1]==i)    cout<<2<<endl;
        else if(a[x][y-1]==i&&a[x+1][y]==i)    cout<<3<<endl;
        else if(a[x][y+1]==i&&a[x+1][y]==i)    cout<<4<<endl;
    }
}
int main()
{
    int size,dr,dc;
    cin>>size>>dr>>dc;
    size=1<<size;
    a[dr][dc]=-1;
    board(1,1,dr,dc,size);
    print();
    return 0;
}
