//
// Created by ellen on 2022-03-21.
//

#include <stdio.h>

int main ()
{

    char c = 'a';
    char *p1 = &c;
    const char **p2=&p1;
    printf("%c\n",**p2);
    const char *p3 = &c;
    // *p3 = 'b'; error
    int *const p4 = &c;

    *p4 = 'b';// 常量指针 ，不可以修改指向
    printf("%c",*p3);
    printf("//////////////////////////////");

    const char *p5 = &c;

    char aaa[10]="string2";

    const char  cc='A';
    char *a = &cc;// 最好不要这样做
    *a = 'v';
    printf("%c",*a);

    return 0;
}