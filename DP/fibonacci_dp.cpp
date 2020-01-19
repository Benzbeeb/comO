#include<bits/stdc++.h>

const int MAXN = 20 ;

int f[MAXN];

int fibo(int k){

    if(f[k] != 0) return f[k];


    if(k == 0 || k == 1)
        f[k] = 1;
    else
        f[k] = fibo(k-1) + fibo(k-2);

    return f[k];
}


int main(){

    int n = 10;

    printf("%d\n",fibo(n));

}