//
// Created by ellen on 2022-03-31.
//

#include <stdio.h>
#include <string.h>

void strCopy(char *dest,const char* src) {
    if (src) {
        while (*src) {
            *dest = *src;
            dest++;
            src++;
        }
        *dest ='\0';//记得拷贝 字符串尾部的 null
    }
}

char *shrink_space(char *dest, const char *src, size_t n){

    if(src){
        size_t i;
        size_t l = 0;
        for (i=0; i<n;i++) {
            if(src[i]!='\t' && src[i]!='\n' && src[i]!=' ') {dest[l++]=src[i];}
            else{
                dest[l++] = ' ';
                size_t j;
                for (j = i+1; j < n; j++) {
                    if(src[j]!=' '&& src[j]!='\t' && src[j]!='\n') break;
                }
                dest[l++] = src[j];
                i = j;

            }
        }
        for (size_t j = l; j <n; j++) {
            dest[j] = '\0';
        }
    }
    return dest;
}

int main ()
{
   /* char *s1 = "hello";
    char s2[10];
    strCopy(s2,s1);
    printf(s2);
    // strncpy(s2,s1, sizeof(char)*3);
    puts(s2);*/

   char s1[20];
   gets(s1);
   char s2[20];
    shrink_space(s2,s1,20);
    puts(s2);
    return 0;
}