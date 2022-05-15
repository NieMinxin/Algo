//
// Created by ellen on 2022-04-21.
//
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void  trim(char *str){
    //去除字符串两边的space
    char *start, *end;
    int len = strlen(str);
    start = str;//指向首字符
    end = str + len -1;//指向最后一个字符

    while(*start && isspace(*start))

        start++;//如果是空格，首地址往前移一位，如果不是，则跳过该循环

    while(*end && isspace(*end))

        *end-- = 0;//如果是空格，末地址往前移一位，并赋结束符

    strcpy(str, start);//把首地址还给str
}

int main ()
{

    char str[80];
    char* argv[2];
    char cmd[30];
    char *delim = " ";
    while(1){
        printf("localhost >:");
        scanf("%s",str);
        fflush(stdin);//这个很关键 ，清空缓冲区
        trim(str);
        char * token;
        token = strtok(str,delim);
        strcpy(cmd,token);

        argv[0] = strtok(NULL," ");
        argv[1] = strtok(NULL," ");
        if(strcmp(cmd,"q")==0){
            break;
        }





        printf("\n");
    }

    return 0;
}