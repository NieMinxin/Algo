//
// Created by ellen on 2022-03-04.
//
#include <stdio.h>
int Fibonacci(int n) {
    if(n<0){
        return -1;
    }
    if(n==0){
        return 0;
    }
    int dp[n];

    dp[0]=1;
    dp[1]=1;


    for(int i=2;i<n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }

    return dp[n-1];
}

int main ()
{

    printf("%d",Fibonacci(5));

    return 0;
}