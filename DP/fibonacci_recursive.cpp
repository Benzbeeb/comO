#include<bits/stdc++.h>

int fibo(int k){
    if(k == 0 || k == 1)
        return 1;
    return fibo(k-1) + fibo(k-2);
}

int main(){

    int n = 10;

    printf("%d\n",fibo(n));

}