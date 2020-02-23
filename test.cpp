#include<bits/stdc++.h>

int n, m ;

const int MAXN = 1000 + 10;

char a[MAXN][MAXN];

int main(){

    scanf("%d%d",&n,&m);

    for(int i = 0 ; i < n ; i ++)
        scanf("%s",a[i]);

    for(int i = 0 ; i < n ; i ++){
        printf("%s\n",a[i]);
    }
}