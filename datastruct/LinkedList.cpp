//
// Created by ellen on 2022-03-27.
//

#include <iostream>
using namespace std;

const int  N = 100010;
int head,e[N],ne[N];// head代表头节点，e[i],代表值，ne[下一个地址]
int index;

void init(){
    head = -1;
    index = 0;
}

void insert_to_head(int value){

        head = index;
        e[index] = value;
        ne[index] = head;//-1 或者有值
        index++;
}
//插入到 k 后
void add(int k,int value){
    e[index]=value;
    ne[index] = ne[k];//指向 k指向的元素
    ne[k] = index;
    index++;
}

//删掉 k 后的节点
void del(int k){
    ne[k] = ne[ne[k]];
}



int main(){

    int n;
    cin >> n;
    init();
    while (n--){

        char op;
        int k,x;
        cin >> op;
        if(op=='H'){
            cin>>x;
            insert_to_head(x);
        }else if(op=='D'){
            cin >> k;
            if(!k){
                // k==0
                head = ne[head];
            }
            del(k-1);
        }else{
            cin >> k >> x;
            add(k-1,x);
        }

    }

    for(int i=head;i!=-1;i=ne[i]) cout << e[i] << " ";
    cout << endl;
    return 0;
}